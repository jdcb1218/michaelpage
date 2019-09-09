<?php

/**
 * @file
 * Custom Module // Created
 * @author Juan David Ceballos.
 */

/**
 * The Callback Dashboard.
 */

function administration_list(){
  
  $item['list']['setup'] = array(
    '#type' => 'item', 
    '#markup' => '1.' . l(t('Setup'), 'admin/config/michaelpage/setup'), 
    '#prefix' => '<div class="setup-form">',
    '#suffix' => '</div>', 
    '#tree' => TRUE,
 );

 $item['list']['batch_fix'] = array(
    '#type' => 'item', 
    '#markup' => '2.' . l(t('Realizar importacion de usuarios'), 'admin/config/michaelpage/batch_fix'), 
    '#prefix' => '<div class="batch-form">',
    '#suffix' => '</div>', 
    '#tree' => TRUE,
 );	

 $item['list']['views_users'] = array(
    '#type' => 'item', 
    '#markup' => '3.' . l(t('Vista de usuarios'), 'admin/config/michaelpage/employers'), 
    '#prefix' => '<div class="views-users-form">',
    '#suffix' => '</div>', 
    '#tree' => TRUE,
 );	

 return $item;
}