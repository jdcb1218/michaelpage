<?php

/**
 * Implementation of hook_views_default_views().
 */

function michaelpage_views_default_views() {
	$view = new view();
	$view->name = 'employers';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'node';
	$view->human_name = 'Employers';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Employers';
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'perm';
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '100';
	$handler->display->display_options['style_plugin'] = 'table';
	/* Field: Content: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	/* Field: Content: Nid */
	$handler->display->display_options['fields']['nid']['id'] = 'nid';
	$handler->display->display_options['fields']['nid']['table'] = 'node';
	$handler->display->display_options['fields']['nid']['field'] = 'nid';
	/* Sort criterion: Content: Post date */
	$handler->display->display_options['sorts']['created']['id'] = 'created';
	$handler->display->display_options['sorts']['created']['table'] = 'node';
	$handler->display->display_options['sorts']['created']['field'] = 'created';
	$handler->display->display_options['sorts']['created']['order'] = 'DESC';
	/* Filter criterion: Content: Published status */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'node';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value'] = 1;
	$handler->display->display_options['filters']['status']['group'] = 1;
	$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
	/* Filter criterion: Content: Type */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'node';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
	  'empleados' => 'empleados',
	);
	/* Filter criterion: Content: Nombre empleado (field_nombre_empleado) */
	$handler->display->display_options['filters']['field_nombre_empleado_value']['id'] = 'field_nombre_empleado_value';
	$handler->display->display_options['filters']['field_nombre_empleado_value']['table'] = 'field_data_field_nombre_empleado';
	$handler->display->display_options['filters']['field_nombre_empleado_value']['field'] = 'field_nombre_empleado_value';
	$handler->display->display_options['filters']['field_nombre_empleado_value']['exposed'] = TRUE;
	$handler->display->display_options['filters']['field_nombre_empleado_value']['expose']['operator_id'] = 'field_nombre_empleado_value_op';
	$handler->display->display_options['filters']['field_nombre_empleado_value']['expose']['label'] = 'Nombre empleado (field_nombre_empleado)';
	$handler->display->display_options['filters']['field_nombre_empleado_value']['expose']['operator'] = 'field_nombre_empleado_value_op';
	$handler->display->display_options['filters']['field_nombre_empleado_value']['expose']['identifier'] = 'field_nombre_empleado_value';
	$handler->display->display_options['filters']['field_nombre_empleado_value']['expose']['remember_roles'] = array(
	  2 => '2',
	);
	/* Filter criterion: Content: Tipo de Salario (field_salario) */
	$handler->display->display_options['filters']['field_salario_tid']['id'] = 'field_salario_tid';
	$handler->display->display_options['filters']['field_salario_tid']['table'] = 'field_data_field_salario';
	$handler->display->display_options['filters']['field_salario_tid']['field'] = 'field_salario_tid';
	$handler->display->display_options['filters']['field_salario_tid']['exposed'] = TRUE;
	$handler->display->display_options['filters']['field_salario_tid']['expose']['operator_id'] = 'field_salario_tid_op';
	$handler->display->display_options['filters']['field_salario_tid']['expose']['label'] = 'Tipo de Salario';
	$handler->display->display_options['filters']['field_salario_tid']['expose']['operator'] = 'field_salario_tid_op';
	$handler->display->display_options['filters']['field_salario_tid']['expose']['identifier'] = 'field_salario_tid';
	$handler->display->display_options['filters']['field_salario_tid']['expose']['remember_roles'] = array(
	  2 => '2',
	);
	$handler->display->display_options['filters']['field_salario_tid']['type'] = 'select';
	$handler->display->display_options['filters']['field_salario_tid']['vocabulary'] = 'tipo_de_salario';
	$handler->display->display_options['filters']['field_salario_tid']['hierarchy'] = 1;

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page');
	$handler->display->display_options['defaults']['fields'] = FALSE;
	/* Field: Content: Nid */
	$handler->display->display_options['fields']['nid']['id'] = 'nid';
	$handler->display->display_options['fields']['nid']['table'] = 'node';
	$handler->display->display_options['fields']['nid']['field'] = 'nid';
	/* Field: Content: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'node';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = 'Nombre del empleado';
	$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
	$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
	/* Field: Content: Link to edit content */
	$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
	$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
	$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
	/* Field: Content: Tipo de Salario */
	$handler->display->display_options['fields']['field_salario']['id'] = 'field_salario';
	$handler->display->display_options['fields']['field_salario']['table'] = 'field_data_field_salario';
	$handler->display->display_options['fields']['field_salario']['field'] = 'field_salario';
	$handler->display->display_options['fields']['field_salario']['type'] = 'taxonomy_term_reference_plain';
	$handler->display->display_options['path'] = 'admin/config/michaelpage/employers';
    // (Export ends here.)
    // Add view to list of views to provide.
    $views[$view->name] = $view;
    // Repeat all of the above for each view the module should provide. At the
    // end, return array of default views.
    return $views;
}