<?php

/**
 * @file
 * Custom Module // Created
 * @author Juan David Ceballos.
 */

/**
 * The batch callback.
 */

function michaelpage_batch_fix() {
  $batch = array(
    'operations' => array(),
    'finished' => 'michaelpage_batch_fix_finished',
    'title' => t('Batch Init'),
    'init_message' => t('Fix is starting...'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Fix has encountered an error.')
  );
  
  
  $request = file_get_contents(variable_get('second_a'));
  $results = json_decode($request);


  foreach ($results as $result) {
    $node = michaelpage_batch_fix_validate($result);
    if (!isset($node)) {
       michaelpage_batch_fix_create($result);
    }else if(isset($node)){
       michaelpage_batch_fix_update($result,$node);
    }
    $batch['operations'][] = array('michaelpage_batch_fix_process', array($result));
  }
  batch_set($batch);
  batch_process('admin/config/michaelpage'); // The path to redirect to when done.
}

/**
 * The batch processor.
 */

function michaelpage_batch_fix_process($word, &$context) {
    $context['message'] = "Now processing $word...";
}

/**
 * The batch finish handler.
 */

function michaelpage_batch_fix_finished($success, $results, $operations) {
  if ($success) {
    drupal_set_message('Fix is complete!');
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE)
    ));
    drupal_set_message($message, 'error');
  }
  drupal_set_message(l('Run again', 'admin/config/michaelpage/batch_fix'));
}