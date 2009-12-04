import java.sql.Connection;
import java.util.Iterator;

import com.hp.hpl.jena.db.DBConnection;
import com.hp.hpl.jena.db.IDBConnection;
import com.hp.hpl.jena.query.Query;
import com.hp.hpl.jena.query.QueryExecution;
import com.hp.hpl.jena.query.QueryExecutionFactory;
import com.hp.hpl.jena.query.QueryFactory;
import com.hp.hpl.jena.query.QuerySolution;
import com.hp.hpl.jena.query.ResultSet;
import com.hp.hpl.jena.query.ResultSetFormatter;
import com.hp.hpl.jena.rdf.model.Model;
import com.hp.hpl.jena.rdf.model.ModelFactory;
import com.hp.hpl.jena.rdf.model.ModelMaker;



public class Query_Engine {
    public static final String DB_URL = "jdbc:mysql://localhost/fma_owl_3?useUnicode=true&characterEncoding=utf8";
    public static final String DB_USER = "fma_test";
    public static final String DB_PASSWD = "test";
    public static final String DB = "MySQL";
    public static final String DB_DRIVER = "com.mysql.jdbc.Driver";

    
    // database connection parameters, with defaults
    private static String s_dbURL = DB_URL;
    private static String s_dbUser = DB_USER;
    private static String s_dbPw = DB_PASSWD;
    private static String s_dbType = DB;
    private static String s_dbDriver = DB_DRIVER;
    
    //public static final String ONT1 = "http://sig.biostr.washington.edu/fma3.0";    

	
	/**
	 * @param args
	 */

    public static void main(String[] args) {
    	//DB_Builder db = new DB_Builder();
    	//db.create_DB();
    	
		// TODO Auto-generated method stub
        // ensure the JDBC driver class is loaded
        try {
            Class.forName( s_dbDriver );
        }
        catch (Exception e) {
            System.err.println( "Failed to load the driver for the database: " + e.getMessage() );
            System.err.println( "Have you got the CLASSPATH set correctly?" );
        }
        
        System.out.println("Tested");

		
        try {
            // Create database connection
            IDBConnection conn  = new DBConnection( s_dbURL, s_dbUser, s_dbPw, s_dbType );
            Connection test =conn.getConnection();
            if(test==null){
            
            	System.out.println("Connection NOT created");
            
            }
            else{
            	System.out.println("Connection IS created");
            }
            
         
            // Create a model maker object
            ModelMaker maker =  ModelFactory.createModelRDBMaker( conn );
            Model m = maker.openModel("http://sig.biostr.washington.edu/fma3.0");
            

             String queryString1 = " PREFIX fma:<http://sig.biostr.washington.edu/fma3.0#> " +
            "SELECT ?esoph_continuity  " +
            "FROM <http://sig.biostr.washington.edu/fma3.0>"+
            "WHERE {fma:Esophagus  fma:continuous_with ?esoph_continuity} " ;
             
             String queryString2 = "PREFIX fma:<http://sig.biostr.washington.edu/fma3.0> " +
             "SELECT ?esoph_continuity FROM <http://sig.biostr.washington.edu/fma3.0> " +
             "WHERE {fma:Esophagus fma:continuous_with ?esoph_continuity}";
             
           /* while(){
            }*/
            String queryString = "";
            
            for(int i=0;i<args.length;i++)
           {
            	queryString = queryString.concat(" "+args[i]);
        	   
           }
            
            
            FMA_Query fma_query = new FMA_Query(m);
            Query query = fma_query.create_Query(queryString);
            ResultSet fma_results = fma_query.execute_query(query);
            ResultSetFormatter.out(System.out, fma_results, query);
            /*for ( ; fma_results.hasNext() ; )
            {
              QuerySolution soln = fma_results.nextSolution() ;
             Iterator names = (soln.varNames());
             while(names.hasNext()){
            	 Object name = names.next();
            	 String name2="esoph_continuity";
            	 
            	 
            	 //String x = soln.getLiteral(name).getString();
            	 
            	 System.out.println("Var is "+name);
         
             }
              
            }*/
            
            
            /*//QueryExecution qexec = QueryExecutionFactory.create(query, m) ;
            try {
              ResultSet results = qexec.execSelect() ;
              for ( ; results.hasNext() ; )
              {
                QuerySolution soln = results.nextSolution() ;
              }
            } finally { qexec.close() ; }*/
            
            conn.close();


       
        }
        catch (Exception e) {
        	
            e.printStackTrace();
            System.exit( 1 );
        }


	}


}
