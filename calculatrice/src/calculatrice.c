#include <tizen.h>
#include "calculatrice.h"

typedef struct appdata {
	Evas_Object *win;
	Evas_Object *conform;
	Evas_Object *label, *zonecalcul, *zonesaisie;
	Evas_Object *button0, *button1, *button2, *button3, *button4, *button5, *button6, *button7, *button8, *button9;
	Evas_Object *buttonAdd, *buttonSubs, *buttonDiv, *buttonMult, *buttonResu;
	Evas_Object *grid;
} appdata_s;

static void
win_delete_request_cb(void *data, Evas_Object *obj, void *event_info)
{
	ui_app_exit();
}

static void
win_back_cb(void *data, Evas_Object *obj, void *event_info)
{
	appdata_s *ad = data;
	/* Let window go to hide state. */
	elm_win_lower(ad->win);
}


static void
clicked_cb(void *data, Evas * e, Evas_Object *obj, void *event_info)
{
	appdata_s * ad = data;

	const char* temp = elm_object_text_get(ad->zonesaisie);
	char* str;

	const char* temp2 = elm_object_text_get(ad->zonecalcul);
	char* str2;

	char* toAppend;
	char* ope;

	strcpy(str, temp);
	strcpy(str2, temp2);

	if (obj == ad->button0)
	{
		toAppend = "0";
	}
	else if(obj == ad->button1)
	{
		toAppend = "1";
	}
	else if(obj == ad->button2)
	{
		toAppend = "2";
	}
	else if(obj == ad->button3)
	{
		toAppend = "3";
	}
	else if(obj == ad->button4)
	{
		toAppend = "4";
	}
	else if(obj == ad->button5)
	{
		toAppend = "5";
	}
	else if(obj == ad->button6)
	{
		toAppend = "6";
	}
	else if(obj == ad->button7)
	{
		toAppend = "7";
	}
	else if(obj == ad->button8)
	{
		toAppend = "8";
	}
	else if(obj == ad->button9)
	{
		toAppend = "9";
	}

	strcat(str, toAppend);
	elm_object_text_set(ad->zonesaisie, str);

	if(obj == ad->buttonAdd)
	{
		ope = " + ";

		strcat(str, ope);

		strcat(str2, str);

		elm_object_text_set(ad->zonesaisie, "");
		elm_object_text_set(ad->zonecalcul, str2);
	}

	else if(obj == ad->buttonSubs)
	{
		ope = " - ";
		strcat(str, ope);

		strcat(str2, str);

		elm_object_text_set(ad->zonesaisie, "");
		elm_object_text_set(ad->zonecalcul, str2);
	}

	else if(obj == ad->buttonMult)
	{
		ope = " x ";
		strcat(str, ope);

		strcat(str2, str);

		elm_object_text_set(ad->zonesaisie, "");
		elm_object_text_set(ad->zonecalcul, str2);
	}

	else if(obj == ad->buttonDiv)
	{
		ope = " / ";
		strcat(str, ope);

		strcat(str2, str);

		elm_object_text_set(ad->zonesaisie, "");
		elm_object_text_set(ad->zonecalcul, str2);
	}

	else if(obj == ad->buttonResu)
	{

	}
}

static void
create_base_gui(appdata_s *ad)
{
	/* Window */
	ad->win = elm_win_util_standard_add(PACKAGE, PACKAGE);
	elm_win_autodel_set(ad->win, EINA_TRUE);

	if (elm_win_wm_rotation_supported_get(ad->win)) {
		int rots[4] = { 0, 90, 180, 270 };
		elm_win_wm_rotation_available_rotations_set(ad->win, (const int *)(&rots), 4);
	}

	evas_object_smart_callback_add(ad->win, "delete,request", win_delete_request_cb, NULL);
	eext_object_event_callback_add(ad->win, EEXT_CALLBACK_BACK, win_back_cb, ad);

	/* Conformant */
	ad->conform = elm_conformant_add(ad->win);
	elm_win_indicator_mode_set(ad->win, ELM_WIN_INDICATOR_SHOW);
	elm_win_indicator_opacity_set(ad->win, ELM_WIN_INDICATOR_OPAQUE);
	evas_object_size_hint_weight_set(ad->conform, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);
	elm_win_resize_object_add(ad->win, ad->conform);
	evas_object_show(ad->conform);

	/*Numbers*/
	ad->button0 = elm_button_add(ad->conform);
	ad->button1 = elm_button_add(ad->conform);
	ad->button2 = elm_button_add(ad->conform);
	ad->button3 = elm_button_add(ad->conform);
	ad->button4 = elm_button_add(ad->conform);
	ad->button5 = elm_button_add(ad->conform);
	ad->button6 = elm_button_add(ad->conform);
	ad->button7 = elm_button_add(ad->conform);
	ad->button8 = elm_button_add(ad->conform);
	ad->button9 = elm_button_add(ad->conform);

	elm_object_text_set(ad->button0, "0");
	elm_object_text_set(ad->button1, "1");
	elm_object_text_set(ad->button2, "2");
	elm_object_text_set(ad->button3, "3");
	elm_object_text_set(ad->button4, "4");
	elm_object_text_set(ad->button5, "5");
	elm_object_text_set(ad->button6, "6");
	elm_object_text_set(ad->button7, "7");
	elm_object_text_set(ad->button8, "8");
	elm_object_text_set(ad->button9, "9");

	evas_object_size_hint_max_set(ad->button0, 20, 20);
	evas_object_size_hint_max_set(ad->button1, 20, 20);
	evas_object_size_hint_max_set(ad->button2, 20, 20);
	evas_object_size_hint_max_set(ad->button3, 20, 20);
	evas_object_size_hint_max_set(ad->button4, 20, 20);
	evas_object_size_hint_max_set(ad->button5, 20, 20);
	evas_object_size_hint_max_set(ad->button6, 20, 20);
	evas_object_size_hint_max_set(ad->button7, 20, 20);
	evas_object_size_hint_max_set(ad->button8, 20, 20);
	evas_object_size_hint_max_set(ad->button9, 20, 20);

	/*Operators*/
	ad->buttonAdd= elm_button_add(ad->conform);
	ad->buttonSubs = elm_button_add(ad->conform);
	ad->buttonDiv = elm_button_add(ad->conform);
	ad->buttonMult = elm_button_add(ad->conform);
	ad->buttonResu = elm_button_add(ad->conform);

	elm_object_text_set(ad->buttonAdd, "+");
	elm_object_text_set(ad->buttonSubs, "-");
	elm_object_text_set(ad->buttonDiv, "/");
	elm_object_text_set(ad->buttonMult, "*");
	elm_object_text_set(ad->buttonResu, "=");

	evas_object_size_hint_max_set(ad->buttonAdd, 40, 40);
	evas_object_size_hint_max_set(ad->buttonSubs, 40, 40);
	evas_object_size_hint_max_set(ad->buttonDiv, 40, 40);
	evas_object_size_hint_max_set(ad->buttonMult, 40, 40);
	evas_object_size_hint_max_set(ad->buttonResu, 40, 40);

	//Les zones de texte//
	ad->zonecalcul = elm_label_add(ad->conform);
	elm_object_text_set(ad->zonecalcul, "");
	evas_object_size_hint_weight_set(ad->zonecalcul, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);

	ad->zonesaisie = elm_label_add(ad->conform);
	elm_object_text_set(ad->zonesaisie, "");
	evas_object_size_hint_weight_set(ad->zonesaisie, EVAS_HINT_EXPAND, EVAS_HINT_EXPAND);


	/*Grid Layout*/
	ad->grid = elm_grid_add(ad->conform);

	elm_grid_pack(ad->grid, ad->zonecalcul, 5, 5, 90, 20);
	elm_grid_pack(ad->grid, ad->zonesaisie, 20, 25, 90, 20);

	//Ajout des nombres//
	elm_grid_pack(ad->grid, ad->button9, 5, 45, 10, 10);
	elm_grid_pack(ad->grid, ad->button8, 20, 45, 10, 10);
	elm_grid_pack(ad->grid, ad->button7, 35, 45, 10, 10);
	elm_grid_pack(ad->grid, ad->button6, 5, 60, 10, 10);
	elm_grid_pack(ad->grid, ad->button5, 20, 60, 10, 10);
	elm_grid_pack(ad->grid, ad->button4, 35, 60, 10, 10);
	elm_grid_pack(ad->grid, ad->button3, 5, 75, 10, 10);
	elm_grid_pack(ad->grid, ad->button2, 20, 75, 10, 10);
	elm_grid_pack(ad->grid, ad->button1, 35, 75, 10, 10);
	elm_grid_pack(ad->grid, ad->button0, 35, 90, 10, 10);
	//-----------------------//

	//Ajout des opérateurs//
	elm_grid_pack(ad->grid, ad->buttonAdd, 65, 45, 10, 10);
	elm_grid_pack(ad->grid, ad->buttonSubs, 80, 45, 10, 10);
	elm_grid_pack(ad->grid, ad->buttonDiv, 65, 60, 10, 10);
	elm_grid_pack(ad->grid, ad->buttonMult, 80, 60, 10, 10);
	elm_grid_pack(ad->grid, ad->buttonResu, 80, 75, 10, 10);
	//------------------------//

	//Ajout de la grille au conformant
	elm_object_content_set(ad->conform, ad->grid);


	//Affichage de tout le truc (zones, nombres etc...)//
	evas_object_show(ad->button0);
	evas_object_show(ad->button1);
	evas_object_show(ad->button2);
	evas_object_show(ad->button3);
	evas_object_show(ad->button4);
	evas_object_show(ad->button5);
	evas_object_show(ad->button6);
	evas_object_show(ad->button7);
	evas_object_show(ad->button8);
	evas_object_show(ad->button9);

	evas_object_show(ad->buttonAdd);
	evas_object_show(ad->buttonSubs);
	evas_object_show(ad->buttonDiv);
	evas_object_show(ad->buttonMult);
	evas_object_show(ad->buttonResu);

	evas_object_show(ad->zonesaisie);
	evas_object_show(ad->zonecalcul);

	evas_object_show(ad->grid);
	//------------------------------//

	//Ajout des évènements//
	evas_object_event_callback_add(ad->button0,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->button1,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->button2,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->button3,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->button4,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->button5,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->button6,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->button7,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->button8,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->button9,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);

	evas_object_event_callback_add(ad->buttonAdd,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->buttonSubs, EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->buttonMult,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->buttonDiv,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	evas_object_event_callback_add(ad->buttonResu,EVAS_CALLBACK_MOUSE_DOWN, clicked_cb, ad);
	//-------------------//

	/* Show window after base gui is set up */
	evas_object_show(ad->win);
}


static bool
app_create(void *data)
{
	/* Hook to take necessary actions before main event loop starts
		Initialize UI resources and application's data
		If this function returns true, the main loop of application starts
		If this function returns false, the application is terminated */
	appdata_s *ad = data;

	create_base_gui(ad);

	return true;
}

static void
app_control(app_control_h app_control, void *data)
{
	/* Handle the launch request. */
}

static void
app_pause(void *data)
{
	/* Take necessary actions when application becomes invisible. */
}

static void
app_resume(void *data)
{
	/* Take necessary actions when application becomes visible. */
}

static void
app_terminate(void *data)
{
	/* Release all resources. */
}

static void
ui_app_lang_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LANGUAGE_CHANGED*/
	char *locale = NULL;
	system_settings_get_value_string(SYSTEM_SETTINGS_KEY_LOCALE_LANGUAGE, &locale);
	elm_language_set(locale);
	free(locale);
	return;
}

static void
ui_app_orient_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_DEVICE_ORIENTATION_CHANGED*/
	return;
}

static void
ui_app_region_changed(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_REGION_FORMAT_CHANGED*/
}

static void
ui_app_low_battery(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_BATTERY*/
}

static void
ui_app_low_memory(app_event_info_h event_info, void *user_data)
{
	/*APP_EVENT_LOW_MEMORY*/
}

int
main(int argc, char *argv[])
{
	appdata_s ad = {0,};
	int ret = 0;

	ui_app_lifecycle_callback_s event_callback = {0,};
	app_event_handler_h handlers[5] = {NULL, };

	event_callback.create = app_create;
	event_callback.terminate = app_terminate;
	event_callback.pause = app_pause;
	event_callback.resume = app_resume;
	event_callback.app_control = app_control;

	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_BATTERY], APP_EVENT_LOW_BATTERY, ui_app_low_battery, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LOW_MEMORY], APP_EVENT_LOW_MEMORY, ui_app_low_memory, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_DEVICE_ORIENTATION_CHANGED], APP_EVENT_DEVICE_ORIENTATION_CHANGED, ui_app_orient_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_LANGUAGE_CHANGED], APP_EVENT_LANGUAGE_CHANGED, ui_app_lang_changed, &ad);
	ui_app_add_event_handler(&handlers[APP_EVENT_REGION_FORMAT_CHANGED], APP_EVENT_REGION_FORMAT_CHANGED, ui_app_region_changed, &ad);
	ui_app_remove_event_handler(handlers[APP_EVENT_LOW_MEMORY]);

	ret = ui_app_main(argc, argv, &event_callback, &ad);
	if (ret != APP_ERROR_NONE) {
		dlog_print(DLOG_ERROR, LOG_TAG, "app_main() is failed. err = %d", ret);
	}

	return ret;
}
