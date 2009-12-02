import com.hp.hpl.jena.query.*;
import com.hp.hpl.jena.rdf.model.Model;


public class FMA_Query {
	private Model model;
	public FMA_Query(Model _model){
		model = _model;
	}
	
	public Query create_Query(String query_string){
		Query query = QueryFactory.create(query_string) ;
		return query;
	}
	
	public ResultSet execute_query(Query query){
		QueryExecution qexec = QueryExecutionFactory.create(query, model) ;
		ResultSet results;
		try{		
			results = qexec.execSelect() ;
			
		}finally{qexec.close();}	
		
		return results;		
	}

}
