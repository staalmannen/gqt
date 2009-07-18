#include <gtk/gtk.h>

int main (int argc, char *argv[])
{
  /*-- Declare the GTK Widgets used in the program --*/
  GtkWidget *window;
  GtkWidget *button;

  /*--  Initialize GTK --*/
  gtk_init (&argc, &argv);

  /*-- Create the new window --*/
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

  /*-- Create a button --*/
  button = gtk_button_new_with_label("Click Me");

  /*-- Add the button to the window --*/
  gtk_container_add(GTK_CONTAINER (window), button);

  /*-- Add a border to the window to give the button a little room --*/
  gtk_container_border_width (GTK_CONTAINER (window), 15);

  /*-- Display the widgets --*/
  gtk_widget_show(button);
  gtk_widget_show(window);

  /*-- Start the GTK event loop --*/
  gtk_main();

  /*-- Return 0 if exit is successful --*/
  return 0;
}
