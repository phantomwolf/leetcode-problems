#include <gtk/gtk.h>

static void
activate (GtkApplication* app,
            gpointer        user_data)
{
    GtkWidget *window;

    // Create a window object
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);
    // Display the window
    gtk_widget_show_all (window);
}

int
main (int    argc,
        char **argv)
{
    GtkApplication *app;
    int status;

    // Create gtk application object
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    // Connect "activate" signal with activate function
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    // Event loop
    // If user closes the application, event loop will return the status
    status = g_application_run (G_APPLICATION (app), argc, argv);
    // Free resource
    g_object_unref (app);
    return status;
}
