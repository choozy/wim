<?php
/**
 * @file
 * Nodes migration.
 */

/**
 * Class NodeMigration.
 */
class NodeMigration extends WIMMigration {

  public $fileName = '';
  public $contentType = '';

}

/**
 * Class BasicPageMigration.
 */
class BasicPageMigration extends NodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments.
   */
  public function __construct(array $arguments) {

    parent::__construct($arguments);
    $this->fileName = $arguments['file_name'];
    $this->contentType = $arguments['content_type'];

    $columns = array(
      array('id', t('Id')),
      array('title', t('Node title')),
      array('body', t('Node body')),
      array('field_image', t('Node image')),
      array('field_tags', t('Node tags')),
      array('field_publication_date', t('Custom publication date')),
      array('field_promoted', t('Promoted flag')),
      array('author', t('Node creator')),
    );

    $this->source = new MigrateSourceCSV(
      $this->dataSources . $this->fileName,
      $columns,
      array('header_rows' => 1)
    );

    $this->destination = new MigrateDestinationNode($this->contentType);
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'varchar',
        'length' => 6,
        'not null' => TRUE,
        'description' => t('ID'),
      ),
    ), MigrateDestinationNode::getKeySchema());

    // Mapped fields.
    $this->addSimpleMappings(array(
      'title',
      'body',
      'field_publication_date',
      'field_promoted',
    ));
    $this->addFieldMapping('field_image', 'field_image')
      ->sourceMigration('WIM_File');
    $this->addFieldMapping('field_image:alt')->defaultValue('');
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('uid', 'author')
      ->sourceMigration('WIM_User')->defaultValue(1);
    $this->addFieldMapping('field_tags', 'field_tags')->separator(',')
      ->sourceMigration('WIM_Term_Tags');
    $this->addFieldMapping('field_tags:source_type')
      ->defaultValue('tid');
  }

}

/**
 * Class ProductMigration.
 *
 * Now it is same as basic page, extend later.
 */
class ProductMigration extends NodeMigration {

}

/**
 * Class NewsMigration.
 */
class NewsMigration extends NodeMigration {

  /**
   * Constructor.
   *
   * @param array $arguments
   *   Arguments.
   */
  public function __construct(array $arguments) {

    parent::__construct($arguments);
    $this->fileName = $arguments['file_name'];
    $this->contentType = $arguments['content_type'];

    $columns = array(
      array('id', t('Id')),
      array('title', t('Node title')),
      array('body', t('Node body')),
      array('field_image', t('Node image')),
      array('field_tags', t('Node tags')),
      array('field_publication_date', t('Custom publication date')),
      array('field_attachment', t('File attachment')),
      array('field_news_category', t('News category')),
      array('field_promoted', t('Promoted flag')),
      array('author', t('Node creator')),
    );

    $this->source = new MigrateSourceCSV(
      $this->dataSources . $this->fileName,
      $columns,
      array('header_rows' => 1)
    );

    $this->destination = new MigrateDestinationNode($this->contentType);
    $this->map = new MigrateSQLMap($this->machineName, array(
      'id' => array(
        'type' => 'varchar',
        'length' => 6,
        'not null' => TRUE,
        'description' => t('ID'),
      ),
    ), MigrateDestinationNode::getKeySchema());

    // Mapped fields.
    $this->addSimpleMappings(array(
      'title',
      'body',
      'field_publication_date',
      'field_promoted',
    ));
    $this->addFieldMapping('field_image', 'field_image')
      ->sourceMigration('WIM_File');
    $this->addFieldMapping('field_image:alt')->defaultValue('');
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_attachment', 'field_attachment')
      ->sourceMigration('WIM_File');
    $this->addFieldMapping('field_attachment:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('uid', 'author')
      ->sourceMigration('WIM_User')->defaultValue(1);
    $this->addFieldMapping('field_tags', 'field_tags')->separator(',')
      ->sourceMigration('WIM_Term_Tags');
    $this->addFieldMapping('field_tags:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_news_category', 'field_news_category')
      ->sourceMigration('WIM_Term_Categories');
    $this->addFieldMapping('field_news_category:source_type')
      ->defaultValue('tid');
  }

}