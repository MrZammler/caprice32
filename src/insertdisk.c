#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>

void insertdisk(char *init_path, char *file)
{
  //printf("In insertdisk.\n");

  GtkWidget *dialog;
  gint xid;

  gtk_init(NULL,NULL);

  dialog = gtk_file_chooser_dialog_new ("Select disk",
     				      NULL,
     				      GTK_FILE_CHOOSER_ACTION_OPEN,
     				      GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
     				      GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT,
     				      NULL);
  
  gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER (dialog), init_path);
  //gtk_file_chooser_set_filter (GTK_FILE_CHOOSER (dialog), "*.dsk"); //for now, do zips later

  if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
    {
      char *filename;
      
      filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
      //open_file (filename);
      //printf("[%s]\n", filename);
      strcpy(file, filename);
      g_free (filename);
    }

  
  gtk_widget_destroy (dialog);
  while (g_main_iteration(FALSE)) 
    gtk_main_quit();
  //printf("After destroy\n");

  //return 0;
}
