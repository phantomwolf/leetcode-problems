#include <arpa/inet.h>
#include <errno.h>
#include <gio/gio.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>


int main(int argc, char *argv[])
{
    GError *err = NULL;
    GSocket *serv_gsock;
    GSocketAddress *gaddr;
    struct sockaddr_in addr;

    /* Create socket */
    serv_gsock = g_socket_new(G_SOCKET_FAMILY_IPV4,
                          G_SOCKET_TYPE_STREAM,
                          0,
                          &err);
    if (!serv_gsock) {
        printf("GSocket creation failure: %s\n", err->message);
        g_clear_error(&err);
    }

    /* Bind to 127.0.0.1 */
    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(10086);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    gaddr = g_socket_address_new_from_native(&addr, sizeof(addr));
    if (!g_socket_bind(serv_gsock, gaddr, TRUE, &err)) {
        printf("GSocket bind failure: %s\n", err->message);
        g_clear_error(&err);
    }

    /* Listen */
    if (!g_socket_listen(serv_gsock, &err)) {
        printf("GSocket listen failure: %s\n", err->message);
        g_clear_error(&err);
    }

    /* Accept */
    gchar buffer[256];
    gsize bytes_read;
    GSocket *clnt_gsock;
    clnt_gsock = g_socket_accept(serv_gsock, NULL, &err);
    bytes_read = g_socket_receive(clnt_gsock, buffer, 256, NULL, &err);
    printf("%u read: <%s>\n", (unsigned int)bytes_read, buffer);
    return 0;
}
