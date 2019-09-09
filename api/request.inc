<?php 

/**
 * @file
 * Custom Module // Created
 * @author Juan David Ceballos.
 */


/**
 * The Function get_keys_endpoint.
 */

function get_keys_endpoint($endpoint){
    $request = file_get_contents($endpoint);
    $query_result = json_decode($request);
    $storage = reset($query_result);

    foreach ($storage as $key => $value) {
    	$data[$key] = $key;
    }

	return $data;
}

/**
 * The batch handler create obj (bundle)->Entity.
 */

function michaelpage_batch_fix_create($result){
  if ($result->employee_name) {
    $vocabulary = taxonomy_vocabulary_machine_name_load('tipo_de_salario');
    $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
    $data_terms = $terms; $max = array_pop($data_terms);
    $args_max = explode("/", $max->name);

    global $user;

    $values = array(
      'type' => 'empleados',
      'uid' => $user->uid,
      'status' => TRUE,
      'comment' => TRUE,
      'promote' => FALSE,
    );

    $entity = entity_create('node', $values);
    $ewrapper = entity_metadata_wrapper('node', $entity);

    if (array_key_exists('employee_name', variable_get('second'))) {
        $ewrapper->title->set($result->employee_name);
        $ewrapper->field_nombre_empleado->set($result->employee_name);
    }

    if (array_key_exists('id', variable_get('second'))) {
        $ewrapper->field_id_remoto->set($result->id);
    }

    if (array_key_exists('employee_age', variable_get('second'))) {
        $ewrapper->field_edad->set($result->employee_age);
    }
    
    if (array_key_exists('employee_salary', variable_get('second'))) {
      $data[$result->id]['storage'] = array();
      foreach ($terms as $key => $value) {
        $args = explode("/", $value->name);
         if ($result->employee_salary <= $args[TRUE] && $data[$result->id]['storage'] != TRUE) {
            $data[$result->id]['storage'] = TRUE;
            $ewrapper->field_salario->set($key);
         } 
         if($result->employee_salary > $args_max[TRUE] && $data[$result->id]['storage'] != TRUE){
            $data[$result->id]['storage'] = TRUE;
            $ewrapper->field_salario->set($max->tid);
         }
      }
    }
    $ewrapper->save(); 
  }
}

/**
 * The batch handler create obj (bundle)->Entity.
 */

function michaelpage_batch_fix_validate($result){
  $entities = array();
  $entities['node'] = array();
  $query = new EntityFieldQuery();
  $entities = $query->entityCondition('entity_type', 'node') 
                  ->entityCondition('bundle', 'empleados')
                  ->fieldCondition('field_nombre_empleado', 'value', $result->employee_name, '=')
                  ->execute(); 
  if (isset($entities['node'])) {
    return $entities['node'];
  }
}

/**
 * The batch handler update obj (bundle)->Entity.
 */

function michaelpage_batch_fix_update($result,$node){
  
    $vocabulary = taxonomy_vocabulary_machine_name_load('tipo_de_salario');
    $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
    $data_terms = $terms; $max = array_pop($data_terms);
    $args_max = explode("/", $max->name);

    $request_up = reset($node); $node = node_load($request_up->nid);
    $ewrapper = entity_metadata_wrapper('node', $node);

    if (array_key_exists('employee_name', variable_get('second'))) {
        $ewrapper->title->set($result->employee_name);
        $ewrapper->field_nombre_empleado->set($result->employee_name);
    }

    if (array_key_exists('id', variable_get('second'))) {
        $ewrapper->field_id_remoto->set($result->id);
    }

    if (array_key_exists('employee_age', variable_get('second'))) {
        $ewrapper->field_edad->set($result->employee_age);
    }
    if (array_key_exists('employee_salary', variable_get('second'))) {
      $data[$result->id]['storage'] = array();
      foreach ($terms as $key => $value) {
        $args = explode("/", $value->name);
         if ($result->employee_salary <= $args[TRUE] && $data[$result->id]['storage'] != TRUE) {
            $data[$result->id]['storage'] = TRUE;
            $ewrapper->field_salario->set($key);
         } 
         if($result->employee_salary > $args_max[TRUE] && $data[$result->id]['storage'] != TRUE){
            $data[$result->id]['storage'] = TRUE;
            $ewrapper->field_salario->set($max->tid);
         }
      }
    }
    $ewrapper->save();  
}