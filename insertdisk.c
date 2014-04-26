#include <stdio.h>
#include <gtk/gtk.h>

int insertdisk(void)
{
  printf("In insertdisk.\n");

  GtkWidget *dialog;
     
  dialog = gtk_file_chooser_dialog_new ("Open File",
     				      parent_window,
     				      GTK_FILE_CHOOSER_ACTION_OPEN,
     				      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
     				      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
     				      NULL);
     
  if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      
      filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
      //open_file (filename);
      g_free (filename);
    }
  
  gtk_widget_destroy (dialog);

  return 0;
}
