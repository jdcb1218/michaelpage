<?php


/**
 * Implements hook_form().
 */

function michaelpage_setup_form($node, &$form_state) {

  $id = 'employers-wrapper-ms';
  $form['#prefix'] = '<div id="' . $id . '">';
  $form['#suffix'] = '</div>';

  //Initiation First Form
  if (!isset($form_state['storage']['billing'])) {
  	$form['first_set']['first'] = array(
  	  '#type' => 'item', 
  	  '#markup' => t('En este modulo usted podra seleccionar <br> las preferencias 
  	  				para su herramienta <br> de manejo de empleados'), 
  	  '#prefix' => '<div class="employers-form">',
  	  '#suffix' => '</div>', 
  	  '#tree' => TRUE,
  	);

    $form['first_set']['save_fs'] = array(
      '#type' => 'button',
      '#value' => t('Siguiente'),
      '#name' => 'save_billing',
      '#ajax' => array(
        'wrapper' => $id,
        'callback' => 'michaelpage_form_ajax',
        ),
      '#attributes' => array(
        'class' => array('btn-success')
        ),
      '#validate' => array('michaelpage_form_validate'),
      );
  }

  //Initiation Second Form.
  if (isset($form_state['storage']['shipping']['access']) && $form_state['storage']['shipping']['access'] === TRUE) {
    $form['second_set']['second_a'] = array(
      '#type' => 'textfield',
      '#title' => t('End point'),
      '#size' => 70,
      '#description' => t('Example : http://dummy.restapiexample.com/api/v1/employees'),
      '#default_value' => variable_get('second_a'),
    );

    $form['second_set']['second_btn'] = array(
      '#type' => 'button',
      '#value' => t('Siguiente'),
      '#name' => 'save_shipping',
      '#ajax' => array(
        'wrapper' => $id,
        'callback' => 'michaelpage_form_ajax',
        ),
      '#attributes' => array(
        'class' => array('btn-info')
        ),
      '#validate' => array('michaelpage_form_validate'),
      );
  }

  //Initiation Third Form.

  if (isset($form_state['storage']['shipping_rates']['access']) && $form_state['storage']['shipping_rates']['access'] === TRUE) {
    $keys = get_keys_endpoint($form_state['values']['second_a']); 
   
  	$form['third_set']['first'] = array(
  	  '#type' => 'item', 
  	  '#markup' => t('Su End point se ha conectado satisfactoriamente <br>'), 
  	  '#prefix' => '<div class="employers-form">',
  	  '#suffix' => '</div>', 
  	  '#tree' => TRUE,
  	);    

  	$form['third_set']['second'] = array(
      '#type' => 'select',
    	'#multiple' => TRUE,
  	  '#title' => t('Por favor seleccione los indixes de su configuracion: @employer->name 
                     sera Asignado titulo del obj'),
	    '#required' => FALSE,
	    '#options' => $keys,
	    '#size' => 5,
      '#weight' => 0,
      '#default_value' => variable_get('second'),
    );

    $form['third_set']['third_btn'] = array(
      '#type' => 'button',
      '#value' => t('Guardar Configuracion'),
      '#name' => 'save_shipping_rates',
      '#ajax' => array(
        'wrapper' => $id,
        'callback' => 'michaelpage_form_ajax',
      ),
      '#attributes' => array(
        'class' => array('btn-success-third')
      ),
      '#validate' => array('michaelpage_form_validate'),
    );
  }


  //Initiation Fourty Form.

  if (isset($form_state['storage']['save_data']['access']) && $form_state['storage']['save_data']['access'] === TRUE) {
    	$form['fourty']['first'] = array(
    	  '#type' => 'item', 
    	  '#markup' => t('Configuracion Correcta<br>'),
    	  '#prefix' => '<div class="employers-form">',
    	  '#suffix' => '</div>', 
    	  '#tree' => TRUE,
  	  );    

  	 $form['fourty']['second'] = array(
  	    '#type' => 'item', 
  	    '#markup' => l(t('Ir al setup nuevamente'), 'admin/config/michaelpage/setup'), 
  	    '#prefix' => '<div class="employers-form">',
  	    '#suffix' => '</div>', 
  	    '#tree' => TRUE,
  	 );

    $form['fourty']['fourty_btn'] = array(
        '#type' => 'button',
        '#value' => t('Salir'),
        '#name' => 'exit',
        '#ajax' => array(
          'wrapper' => $id,
          'callback' => 'ajax_exit',
        ),
     );
  }
  return $form;
}


/*
 * Implements hook_validate().
 */

function michaelpage_form_validate($form, &$form_state) {

 switch ($form_state['clicked_button']['#name']) {

  case 'save_billing':
    $form_state['storage']['billing'] = $form_state['values'];
    $form_state['storage']['billing']['access'] = TRUE;
    $form_state['storage']['shipping']['access'] = TRUE;
    break;

  case 'save_shipping':
    $form_state['storage']['shipping'] = $form_state['values'];
    $form_state['storage']['shipping']['access'] = FALSE;
    $form_state['storage']['shipping_rates']['access'] = TRUE;
   break;

  case 'save_shipping_rates':
   	$form_state['storage']['shipping_rates'] = $form_state['values'];
   	$form_state['storage']['shipping_rates']['access'] = FALSE;
   	$form_state['storage']['save_data']['access'] = TRUE;
   break;

  }
}

/**
  * Implements ajax form.
*/

function michaelpage_form_ajax($form, &$form_state) {

  foreach ($form_state['values'] as $key => $value) {
    variable_set($key, $value);
  } 
	$commands[] = ajax_command_replace('#employers-wrapper-ms', render($form));

  return  array(
     '#type' => 'ajax',
     '#commands' => $commands,
	);

}

/**
  * Implements Ajax Exit.
*/

function ajax_exit(){
	ctools_include('ajax'); ctools_add_js('ajax-responder');
	$commands[] = ctools_ajax_command_redirect('admin/config/michaelpage');
	print ajax_render($commands);
	exit;
}