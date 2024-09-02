#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

// Declarar widgets globais
GtkWidget *text_view;
GtkWidget *entry;

// Função que redireciona o texto da entrada para a text view
void on_button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *input_text = gtk_entry_get_text(GTK_ENTRY(entry));
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    gtk_text_buffer_set_text(buffer, input_text, -1);
}

// Função principal
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Entrada e Saída com GTK+");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), box);

    entry = gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(box), entry, FALSE, FALSE, 0);

    text_view = gtk_text_view_new();
    gtk_box_pack_start(GTK_BOX(box), text_view, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Enviar Texto");
    gtk_box_pack_start(GTK_BOX(box), button, FALSE, FALSE, 0);
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
