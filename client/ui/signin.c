#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <ctype.h>

GtkWidget	*SignInWindow;
GtkWidget	*SignInFixed;
GtkWidget	*SignInTitle;
GtkWidget	*SignInLogin;
GtkWidget	*SignInPassword;
GtkWidget	*SignInBtn;


GtkBuilder	*builder;



int main2(int argc, char *argv[]) {
	gtk_init(&argc, &argv);
	
	builder = gtk_builder_new_from_file ("auth.glade");

	SignInWindow = GTK_WIDGET(gtk_builder_get_object(builder, "SignInWindow"));

	SignInFixed = GTK_WIDGET(gtk_builder_get_object(builder, "SignInFixed"));
	
	SignInTitle = GTK_WIDGET(gtk_builder_get_object(builder, "SignInTitle"));
	SignInLogin = GTK_WIDGET(gtk_builder_get_object(builder, "SignInLogin"));

	SignInBtn = GTK_WIDGET(gtk_builder_get_object(builder, "SignInBtn"));

	SignInPassword = GTK_WIDGET(gtk_builder_get_object(builder, "SignInPassword"));	

	

	gtk_widget_show(SignInWindow);

	gtk_main(); 

	return EXIT_SUCCESS;
}
