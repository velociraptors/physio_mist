
import java.sql.Connection;

import com.hp.hpl.jena.db.DBConnection;
import com.hp.hpl.jena.db.IDBConnection;
import com.hp.hpl.jena.ontology.OntDocumentManager;
import com.hp.hpl.jena.ontology.OntModelSpec;
import com.hp.hpl.jena.rdf.model.*;
import com.hp.hpl.jena.ontology.OntModel;

public class DB_Builder {

    public String DB_URL = "jdbc:mysql://localhost/fma_owl_3?useUnicode=true&characterEncoding=utf8";
    public String DB_USER = "fma_test";
    public String DB_PASSWD = "test";
    public String DB = "MySQL";
    public static final String DB_DRIVER = "com.mysql.jdbc.Driver";

    
    // database connection parameters, with defaults
    private String s_dbURL = DB_URL;
    private String s_dbUser = DB_USER;
    private String s_dbPw = DB_PASSWD;
    private String s_dbType = DB;
    private String s_dbDriver = DB_DRIVER;
    
    public String ONT1 = "http://sig.biostr.washington.edu/fma3.0";
    
    // source URL to load data from; if null, use default
    private String s_source;
    
    public void create_DB(){
		s_source = getDefaultSource();
		// TODO Auto-generated method stub
        // ensure the JDBC driver class is loaded
        try {
            Class.forName( s_dbDriver );
        }
        catch (Exception e) {
            System.err.println( "Failed to load the driver for the database: " + e.getMessage() );
            System.err.println( "Have you got the CLASSPATH set correctly?" );
        }
        
		
        
        // Create database connection
        try{
        	IDBConnection conn  = new DBConnection( s_dbURL, s_dbUser, s_dbPw, s_dbType );
            Connection test =conn.getConnection();
            if(test==null){
            
            	System.out.println("Connection NOT created");
            
            }
            else{
            	System.out.println("Connection IS created");
            }
            
//          Create a model maker object
            ModelMaker maker =  ModelFactory.createModelRDBMaker( conn );
            Model base = maker.createModel("http://sig.biostr.washington.edu/fma3.0");
//          use the model maker to get the base model as a persistent model
            // strict=false, so we get an existing model by that name if it exists
            // or create a new one
            //Model base = maker.createModel( s_source, false );
            // now we plug that base model into an ontology model that also uses
            // the given model maker to create storage for imported models
            OntModel m = ModelFactory.createOntologyModel( getModelSpec( maker ), base );

            // now load the source document, which will also load any imports
            m.read( s_source );


        }catch(Exception e){           
        e.printStackTrace();
        System.exit( 1 );
        }

    }
    private String getDefaultSource() {
        // use the ont doc mgr to map from a generic URN to a local source file
        OntDocumentManager.getInstance().addAltEntry( ONT1, "file:fma3.0.owl" );
    	//OntDocumentManager.getInstance().addAltEntry( ONT3, "file:camera.owl" );

        return ONT1;
    }
    public OntModelSpec getModelSpec( ModelMaker maker ) {
        // create a spec for the new ont model that will use no inference over models
        // made by the given maker (which is where we get the persistent models from)
        OntModelSpec spec = new OntModelSpec( OntModelSpec.OWL_MEM );
        spec.setImportModelMaker( maker );

        return spec;
    }



}
