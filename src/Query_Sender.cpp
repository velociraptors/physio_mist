/**************************************************************************************************
Query_Sender.cpp
Contributor(s):	E. Zeynep Erson
Created on:		02-Sept-2009
Description:		
**************************************************************************************************/

#include <fstream>

#include <jni.h>
#include <stdlib.h>
#include <string.h>

//#pragma comment(lib,"jvm.lib");
#define PATH_SEPARATOR ';' /* define it to be ':' on Solaris */
//#define USER_CLASSPATH "C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\implementation\\zeynep\\integrative_phys_local_copy\\trunk\\Java\\FMA_Query_Engine.jar; C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\Jenaroot\\Jena-2.5.7\\lib\\jena.jar; C:\\Documents and Settings\\Zeynep\\My Documents\\educational\\research\\Jenaroot\\Jena-2.5.7\\lib\\arq.jar" /* where Prog.class is */

//#define USER_CLASSPATH "C:\\Documents and Settings\\Zeynep\\eclipseworkspace\\hello_world\\hello_world.jar" /* where Prog.class is */
//#define USER_CLASSPATH "C:\\" /* where Prog.class is */
//#define USER_CLASSPATH "." /* where Prog.class is */


//! Data structure for sending queries to the fma ontology
/*!
The Java virtual machine is created and the appropriate java class is called using JNI interface.
The java class implementing the SPARQL query engine is the "Query_Engine"

\todo For the classpath to be set as the java classpath, put everything in a single jar file.
*/

class Query_Sender
{

public:
	//! Default constructor
	/*!

	*/
	Query_Sender(){
		if (create_JVM()){
		}

		else{
			env = NULL;
			jvm = NULL;
		}

	}

	//! Method to call the query engine
	/*!
	Calls the query engine through the JNI interface.
	\param query_string a character array for the SPARQL query string
	*/
	/*For test purposes the query results are written in a file, "debugging.txt". 
	If an error occurs, the log is kept in "debugging_error.txt".
	This action is carried out by the "Query_Eingine"
	*/
	void call_query_engine(char *query_string){

		cls = env->FindClass("QuerySystem/Query_Engine");	

		if (cls == NULL) {
			destroy();
		}

		mid = (env)->GetStaticMethodID( cls, "main",
			"([Ljava/lang/String;)V");

		if (mid == NULL) {
			destroy();
		}
		/*
		For test purposes: Prepare the query as the argument, and call the main method.
		*/

		//const char *q_str = " PREFIX fma:<http://sig.biostr.washington.edu/fma3.0#> SELECT ?esoph_continuity  FROM <http://sig.biostr.washington.edu/fma3.0> WHERE {fma:Aorta  fma:continuous_with ?esoph_continuity}";
		jstr = (env)->NewStringUTF(query_string);
		if (jstr == NULL) {
			destroy();
		}

		stringClass = (env)->FindClass("java/lang/String");

		args = (env)->NewObjectArray(1, stringClass, jstr);
		if (args == NULL) {
			destroy();
		}

		(env)->CallStaticVoidMethod(cls, mid, args);

		this->terminate_JVM();	    		 

	};
private:

	//! Private method for JVM
	/*!
	Creates the JVM using the classpath defined
	\todo For the classpath to be set as the java classpath, put everything in a single jar file.
	*/
	bool create_JVM(){

#ifdef JNI_VERSION_1_2
		JavaVMInitArgs vm_args;
		JavaVMOption options[1];


		//List all the jars that are used in the java application.
		options[0].optionString = "-Djava.class.path=C:\\antlr-2.7.5;C:\\arq.jar;C:\\arq-extra.jar;C:\\commons-logging-1.1.1.jar;C:\\concurrent.jar;C:\\icu4j_3_4.jar;C:\\iri.jar;C:\\jena.jar;C:\\jenatest.jar;C:\\json.jar;C:\\junit.jar;C:\\log4j-1.2.12.jar;C:\\lucene-core-2.3.1.jar;C:\\stax-api-1.0.jar;C:\\wstx-asl-3.0.0.jar;C:\\xercesImpl.jar;C:\\xml-apis.jar;C:\\FMA_Query_Engine.jar;C:\\mysql-connector-java-3.1.14-bin.jar" ; 


		vm_args.version = 0x00010002;
		vm_args.options = options;
		vm_args.nOptions = 1;
		vm_args.ignoreUnrecognized = JNI_TRUE;
		/* Create the Java VM */
		res = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);
#else
		JDK1_1InitArgs vm_args;
		char classpath[1024];
		vm_args.version = 0x00010001;
		JNI_GetDefaultJavaVMInitArgs(&vm_args);
		/* Append USER_CLASSPATH to the default system class path */
		sprintf(classpath, "%s%c%s",
			vm_args.classpath, PATH_SEPARATOR, USER_CLASSPATH);
		vm_args.classpath = classpath;
		/* Create the Java VM */
		res = JNI_CreateJavaVM(&jvm, &env, &vm_args);
#endif /* JNI_VERSION_1_2 */


		if (res < 0) {
			fprintf(stderr, "Can't create Java VM\n");
			return false;
		}
		return true;
	};


	void terminate_JVM(){

		(jvm)->DestroyJavaVM();
	};



	//! For handling JNI exceptions and errors
	/*!
	If an exception occurs in JNI, the following steps are executed to get the log of the exception
	*/
	void destroy(){

		if (env->ExceptionCheck()) {		 
			jthrowable e = env->ExceptionOccurred();

			char buf[1024];
			strnset(buf, 0, 1024);

			// have to clear the exception before JNI will work again.
			env->ExceptionClear();

			jclass eclass = env->GetObjectClass(e);

			mid = env->GetMethodID(eclass, "toString", "()Ljava/lang/String;");

			jstring jErrorMsg = (jstring) env->CallObjectMethod(e, mid);
			const char* cErrorMsg = env->GetStringUTFChars(jErrorMsg, NULL);

			strcpy(buf, cErrorMsg);

			env->ReleaseStringUTFChars(jErrorMsg, cErrorMsg);
			std::ofstream log_file("logfile.txt",std::ifstream::binary);
			log_file.write(buf,1024);
			log_file.close();		
		}
	};

protected:

	//! JNI variable
	JNIEnv *env;

	//! JNI variable
	JavaVM *jvm;

	//! JNI variable
	jint res;
	jclass cls;
	jmethodID mid;
	jstring jstr;
	jclass stringClass;
	jobjectArray args;

};