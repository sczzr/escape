//
// Created by Shawn on 2/25/2022.
//
#include "js_port.h"
#include "jerryscript.h"
#include "jerryscript-ext/handlers.h"
#include "jerryscript-ext/properties.h"
#include "jerryscript-ext/print.h"
static void main_init_engine ()
{
    jerry_init (JERRY_INIT_EMPTY);
    jerry_promise_on_event (JERRY_PROMISE_EVENT_FILTER_ERROR, jerryx_handler_promise_reject, NULL);
    jerryx_register_global ("assert", jerryx_handler_assert);
    jerryx_register_global ("gc", jerryx_handler_gc);
    jerryx_register_global ("print", jerryx_handler_print);
    jerryx_register_global ("sourceName", jerryx_handler_source_name);
    jerryx_register_global ("createRealm", jerryx_handler_create_realm);
}

int jerry_test() {
    const jerry_char_t scrpit[] = "print (\"Hello JerryScript!\");";
    const jerry_length_t script_size = sizeof(scrpit) - 1;
    main_init_engine();
    jerry_value_t parsed_code = jerry_parse(scrpit, script_size, (const jerry_parse_options_t *) JERRY_PARSE_NO_OPTS);
    if (!jerry_value_is_error(parsed_code)) {
        /* Execute the parsed source code in the Global scope */
        jerry_value_t ret_value = jerry_run(parsed_code);
        if (jerry_value_is_exception (ret_value))
        {
            jerryx_print_unhandled_exception (ret_value);
            goto exit;
        }
        /* Returned value must be freed */
        jerry_value_free(ret_value);
    }
    jerry_value_free(parsed_code);
exit:
    jerry_cleanup();
    return 0;
}