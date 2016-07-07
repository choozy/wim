@faq @faq-view @stability @api
Feature: View FAQ
  Benefit: In order to view textual information on the site
  Role: AN
  Goal/desire: View FAQ

  Scenario: As a AN I should be able to see FAQ
    Given I am an anonymous user
    And tags terms:
      | name |
      | TAG1 |
      | TAG2 |
    And I am viewing a "faq":
      | title                            | FAQ-QUESTION    |
      | body                             | ANSWER-CONTENT  |
      | field_faq_additional_information | ADDITIONAL-INFO |
      | field_tags                       | TAG1, TAG2      |
    Then I should not see the link "Edit"
    And I should not see "BSCPGTEST"
    And I should see "FAQ-QUESTION"
    And I should see "ANSWER-CONTENT"
    And I should see "ADDITIONAL-INFO"
    And I should see "TAG1"
    And I should see "TAG2"