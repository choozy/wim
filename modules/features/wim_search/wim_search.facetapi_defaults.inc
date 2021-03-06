<?php
/**
 * @file
 * wim_search.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function wim_search_facetapi_default_facet_settings() {
  $export = [];

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::bundle';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'bundle';
  $facet->enabled = FALSE;
  $facet->settings = [
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => [
      'roles' => [],
      'facets' => [],
      'reverse_dependency' => FALSE,
      'force_deactivation' => TRUE,
      'regex' => FALSE,
    ],
    'facet_mincount' => '1',
    'facet_missing' => 0,
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'term',
    'limit_active_items' => 0,
  ];
  $export['apachesolr@solr::bundle'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr::created';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = '';
  $facet->facet = 'created';
  $facet->enabled = FALSE;
  $facet->settings = [
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => [
      'roles' => [],
      'bundle' => 'none',
      'bundle_selected' => [],
    ],
    'facet_mincount' => 1,
    'facet_missing' => 0,
    'flatten' => 0,
    'individual_parent' => 0,
    'query_type' => 'date_range',
    'limit_active_items' => 0,
    'date_granularity' => 'MONTH',
  ];
  $export['apachesolr@solr::created'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:bundle';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'bundle';
  $facet->enabled = TRUE;
  $facet->settings = [
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => [],
    'active_sorts' => [
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ],
    'sort_weight' => [
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ],
    'sort_order' => [
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ],
    'empty_behavior' => 'text',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '5',
    'nofollow' => 1,
    'show_expanded' => 0,
    'ranges' => [
      'past_hour' => [
        'label' => 'Past hour',
        'machine_name' => 'past_hour',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '0',
        'delete' => 0,
      ],
      'past_24_hours' => [
        'label' => 'Past 24 hours',
        'machine_name' => 'past_24_hours',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '24',
        'date_range_start_unit' => 'HOUR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '1',
        'delete' => 0,
      ],
      'past_week' => [
        'label' => 'Past week',
        'machine_name' => 'past_week',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '7',
        'date_range_start_unit' => 'DAY',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '2',
        'delete' => 0,
      ],
      'past_month' => [
        'label' => 'Past month',
        'machine_name' => 'past_month',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'MONTH',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '3',
        'delete' => 0,
      ],
      'past_year' => [
        'label' => 'Past year',
        'machine_name' => 'past_year',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '4',
        'delete' => 0,
      ],
    ],
    'date_ranges' => [
      'add_range' => 'Add a new date range',
    ],
    'empty_text' => [
      'value' => '<p>No matches for this filter.</p>',
      'format' => 'full_html',
    ],
  ];
  $export['apachesolr@solr:block:bundle'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'apachesolr@solr:block:created';
  $facet->searcher = 'apachesolr@solr';
  $facet->realm = 'block';
  $facet->facet = 'created';
  $facet->enabled = TRUE;
  $facet->settings = [
    'weight' => 0,
    'widget' => 'date_range_checkboxes',
    'filters' => [],
    'active_sorts' => [
      'active' => 0,
      'indexed' => 0,
      'count' => 0,
      'display' => 0,
    ],
    'sort_weight' => [
      'active' => '-50',
      'indexed' => '-49',
      'count' => '0',
      'display' => '0',
    ],
    'sort_order' => [
      'active' => '3',
      'indexed' => '4',
      'count' => '4',
      'display' => '3',
    ],
    'empty_behavior' => 'text',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'soft_limit' => '5',
    'nofollow' => 1,
    'show_expanded' => 0,
    'ranges' => [
      'last_month' => [
        'label' => 'Last month',
        'machine_name' => 'last_month',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'MONTH',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '0',
        'delete' => 0,
      ],
      'last_6_months' => [
        'label' => 'Last 6 months',
        'machine_name' => 'last_6_months',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '6',
        'date_range_start_unit' => 'MONTH',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '1',
        'delete' => 0,
      ],
      'last_year' => [
        'label' => 'Last year',
        'machine_name' => 'last_year',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '1',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => 'NOW',
        'date_range_end_amount' => '',
        'date_range_end_unit' => 'HOUR',
        'weight' => '2',
        'delete' => 0,
      ],
      'older_than_a_year' => [
        'label' => 'Older than a year',
        'machine_name' => 'older_than_a_year',
        'date_range_start_op' => '-',
        'date_range_start_amount' => '5',
        'date_range_start_unit' => 'YEAR',
        'date_range_end_op' => '-',
        'date_range_end_amount' => '1',
        'date_range_end_unit' => 'YEAR',
        'weight' => '3',
        'delete' => 0,
      ],
    ],
    'date_ranges' => [
      'add_range' => 'Add a new date range',
    ],
    'empty_text' => [
      'value' => '<p>No matches for this filter.</p>',
      'format' => 'full_html',
    ],
  ];
  $export['apachesolr@solr:block:created'] = $facet;

  return $export;
}
