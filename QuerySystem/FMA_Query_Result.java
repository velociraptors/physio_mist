
public class FMA_Query_Result {
	private String result_string;
	public FMA_Query_Result(String result){
		result_string = result;
	}
	
	public PhySIM_List get_parsed_result(){
		String parsed_result = result_string;
		PhySIM_List results = new PhySIM_List();
		results.add(parsed_result);
		return results;
	}

}
