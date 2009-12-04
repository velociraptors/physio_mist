Physio_MIST
Mark Caral, Sara Cummins, BarbaraJoy Jones

REQUIREMENTS
JDK 6 Update 17: http://java.sun.com/javase/downloads/index.jsp
	The directory containing jvm.dll must be in the user's PATH environment variable.
Open Physio_MIST.sln in Visual Studio and build the project.

QUERY REQUIREMENTS
MySQL 5.0 and the JDBC: http://dev.mysql.com/downloads/connector/j/5.0.html
Make a database named "fma_owl_3"
Make a MySQL user "fma_test" with the password set to "test" with full privileges on the FMA database.
Unzip the fma3.0.owl.zip file in the QuerySystem directory and run DB_Builder.java
Building the database can take a significant amount of time, but only needs to be done once.

LOADING MODELS
Select File->Load from the main menu.
Browse for the desired file (either an MML text file or an XML file conforming to the Physio_MIST schema) and click the Open button.
A sample model (meal_model.xml) is located in the source directory.

SAVING MODELS
Select File->Save from the main menu.
Enter the desired file name and click the Save button.

EDITING MODELS
Select an item in either the Parameter or Variable tables and click the Edit button. Input must conform to the MML standard, except for the Anatomical Structure and the Description fields.

QUERYING
Select the desired structure in the ontology tree. Right click and select "Find Related Structures..." then select the desired relationship type and click the Run Query button.
