#include <gtk/gtk.h>

static void
print_hello (GtkWidget *widget,
               gpointer   data)
{
    // Print to stdout
    g_print ("Hello World\n");
}

static void
activate (GtkApplication *app,
            gpointer        user_data)
{
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *button_box;

    // Create gtk window object
    window = gtk_application_window_new (app);
    gtk_window_set_title (GTK_WINDOW (window), "Window");
    gtk_window_set_default_size (GTK_WINDOW (window), 200, 200);

    // Create button box object
    button_box = gtk_button_box_new (GTK_ORIENTATION_HORIZONTAL);
    // Add button_box to window
    gtk_container_add (GTK_CONTAINER (window), button_box);

    // Create button object
    button = gtk_button_new_with_label ("Hello World");
    // Connect "clicked" signal with "print_hello" function
    g_signal_connect (button, "clicked", G_CALLBACK (print_hello), NULL);
    // When "clicked" signal is sent, call gtk_widget_destroy(window, button)
    // Since gtk_widget_destroy only accepts one argument, the second argument "button" will be ignored.
    g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
    // Add button to button_box
    gtk_container_add (GTK_CONTAINER (button_box), button);
    // Display the window
    gtk_widget_show_all (window);
}

int
main (int    argc,
        char **argv)
{
    GtkApplication *app;
    int status;

    // Create application object
    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    // Connect "activate" signal with "activate" function
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    // Event loop
    status = g_application_run (G_APPLICATION (app), argc, argv);
    // Free resource
    g_object_unref (app);

    return status;
}
