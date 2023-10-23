({

customProcess : function(params)
{
   try
   {
      // log all input parameters
      printParams(params);

      /* -- example : if you want to override default behaviour with your custom code :

      var action = params[5];
      var entity_name = params[6];
      if ((action == "FULL_CLASS_NAME") && (entity_name == "myEntity"))
      {
         return "quit with my custom code here";
      }
      -- */

      /* -- note : you can define your own placeholder in the template, it must start with @@CUSTOM_, for example : @@CUSTOM_MY_ACTION@@
                   then, in the custom script, check if you are processing your custom action with this code :

      var action = params[5];
      if (action == "CUSTOM_MY_ACTION")
      {
         return "quit with my custom code here";
      }
      -- */

      /* -- example : how to get more details about an entity

      var entity_id = params[13];
      printEntityDetails(entity_id);
      -- */

      /* -- example : how to iterate over each property of an entity

      var entity_id = params[13];
      var entity_details = helper.getEntityDetails(entity_id);
      var entity_list_of_properties_id = ((entity_details.length > 0) ? entity_details[10] : "");
      var entity_list_of_properties_array = entity_list_of_properties_id.split("|");
      for (var idx = 0; idx < entity_list_of_properties_array.length; idx++)
      {
         var property_id = entity_list_of_properties_array[idx];
         var property_details = helper.getPropertyDetails(property_id);
         printPropertyDetails(property_id);
         // ...
      }
      -- */

      /* -- example : how to get an entity meta-data

      var entity_id = params[13];
      var my_meta_data = helper.getEntityMetaData(entity_id, "MY_META_DATA_KEY");
      -- */

      /* -- example : how to get/set an environment variable value (QT_DIR environment variable in this example)

      var env_var = helper.getEnvironmentVariable("QT_DIR");
      var set_env_var_ok = helper.setEnvironmentVariable("MY_ENV_VAR", "my_value");
      -- */

      /* -- example : how to read full content of a text file (javascript 'file' class is a QFile wrapper, documentation available here : http://doc.qt.io/qt-5/qfile.html)
                      for a full list of 'file' class methods available by script, please go to the end of this document

      var f1 = new file();
      var f1_content = f1.readAll("C:\\Temp\\my_file.txt");
      -- */

      /* -- example : how to write to a file (javascript 'file' class is a QFile wrapper, documentation available here : http://doc.qt.io/qt-5/qfile.html)
                      for a full list of 'file' class methods available by script, please go to the end of this document

      var f2 = new file();
      f2.setFileName("C:\\Temp\\file_generated_by_script.txt");
      f2.open(26); // (QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text) = (2 + 8 + 16)
      f2.write("aaa");
      f2.write("bbb");
      f2.close();
      -- */

      /* -- example : how to get a list of all entities/enumerations of a project

      var listOfAllEntities = helper.getListOfAllEntities(); // 'listOfAllEntities' variable is an array, each item of this array contains : <entity_id>|<entity_name>
      var listOfAllEnums = helper.getListOfAllEnums(); // 'listOfAllEnums' variable is an array, each item of this array contains : <enum_id>|<enum_name>
      -- */

      /* -- example : how to get all settings defined in QxEntityEditor (global settings, project settings and plugin settings)

      var globalSettings = helper.getQxEEGlobalSettingsJson();    // the result is a string in JSON format ==> so just use JSON.parse() function to get a javascript object instance
      var projectSettings = helper.getQxEEProjectSettingsJson();  // the result is a string in JSON format ==> so just use JSON.parse() function to get a javascript object instance
      var pluginSettings = helper.getQxEEPluginSetingsJson();     // the result is a string in JSON format ==> so just use JSON.parse() function to get a javascript object instance

      print(globalSettings); helper.print(globalSettings);
      print(projectSettings); helper.print(projectSettings);
      print(pluginSettings); helper.print(pluginSettings);

      globalSettings = JSON.parse(globalSettings);    // Now 'globalSettings' is a javascript object instance
      projectSettings = JSON.parse(projectSettings);  // Now 'projectSettings' is a javascript object instance
      pluginSettings = JSON.parse(pluginSettings);    // Now 'pluginSettings' is a javascript object instance
      -- */

      /* -- example : how to use QxOrm JSON REST API module (QxRestApi) to fetch/update/delete QxEntityEditor project data
                      see /QxOrm/test/qxBlogRestApi/ sample project (or QxOrm manual) for a list of JSON queries examples

      var json_api = new api();
      var json_response = json_api.processRequest("<my_json_query>");
      -- */

      // quit with 'params[0]' means : not change the default behaviour
      return params[0];
   }
   catch (err)
   { return ("[CustomScriptError] an unexpected error occurred : " + err); }
}

})

function printParams(params)
{
   var log = "";
   log = log + "\n - default_value = " + params[0];
   log = log + "\n - project_name = " + params[1];
   log = log + "\n - project_file = " + params[2];
   log = log + "\n - plugin_name = " + params[3];
   log = log + "\n - current_file = " + params[4];
   log = log + "\n - action = " + params[5];
   log = log + "\n - entity_name = " + params[6];
   log = log + "\n - entity_table_name = " + params[7];
   log = log + "\n - property_name = " + params[8];
   log = log + "\n - property_type = " + params[9];
   log = log + "\n - property_column_name = " + params[10];
   log = log + "\n - property_is_primary_key = " + params[11];
   log = log + "\n - enumeration_name = " + params[12];
   log = log + "\n - entity_id = " + params[13];
   log = log + "\n - property_id = " + params[14];
   log = log + "\n - enumeration_id = " + params[15];
   log = log + "\n - output_location = " + params[16];

   print(log); // print value to the custom script debugger window
   helper.print(log); // print value to the standard output (for example, on Windows, use the 'DebugView' application to see all logs)
   return log;
}

function printEntityDetails(entity_id)
{
   var details = helper.getEntityDetails(entity_id);
   if (details.length == 0) { return details; }

   var log = "";
   log = log + "\n - entity_id = " + details[0];
   log = log + "\n - entity_key = " + details[1];
   log = log + "\n - entity_name = " + details[2];
   log = log + "\n - entity_namespace = " + details[3];
   log = log + "\n - entity_tablename = " + details[4];
   log = log + "\n - entity_description = " + details[5];
   log = log + "\n - entity_is_read_only = " + details[6];
   log = log + "\n - entity_is_abstract = " + details[7];
   log = log + "\n - entity_version = " + details[8];
   log = log + "\n - entity_primary_key_property_id = " + details[9];
   log = log + "\n - entity_list_of_properties_id = " + details[10];
   log = log + "\n - entity_has_triggers = " + details[11];
   log = log + "\n - entity_trigger_on_before_fetch = " + details[12];
   log = log + "\n - entity_trigger_on_after_fetch = " + details[13];
   log = log + "\n - entity_trigger_on_before_insert = " + details[14];
   log = log + "\n - entity_trigger_on_after_insert = " + details[15];
   log = log + "\n - entity_trigger_on_before_update = " + details[16];
   log = log + "\n - entity_trigger_on_after_update = " + details[17];
   log = log + "\n - entity_trigger_on_before_delete = " + details[18];
   log = log + "\n - entity_trigger_on_after_delete = " + details[19];
   log = log + "\n - entity_parent_id = " + details[20];
   log = log + "\n - entity_soft_delete_column = " + details[21];
   log = log + "\n - entity_validator_method = " + details[22];

   print(log); // print value to the custom script debugger window
   helper.print(log); // print value to the standard output (for example, on Windows, use the 'DebugView' application to see all logs)
   return details;
}

function printPropertyDetails(property_id)
{
   var details = helper.getPropertyDetails(property_id);
   if (details.length == 0) { return details; }

   var log = "";
   log = log + "\n - property_id = " + details[0];
   log = log + "\n - property_key = " + details[1];
   log = log + "\n - property_name = " + details[2];
   log = log + "\n - property_column_name = " + details[3];
   log = log + "\n - property_description = " + details[4];
   log = log + "\n - property_type = " + details[5];
   log = log + "\n - property_version = " + details[6];
   log = log + "\n - property_entity_id = " + details[7];
   log = log + "\n - property_is_read_only = " + details[8];
   log = log + "\n - property_is_primary_key = " + details[9];
   log = log + "\n - property_is_serializable = " + details[10];
   log = log + "\n - property_is_transient = " + details[11];
   log = log + "\n - property_is_obsolete = " + details[12];
   log = log + "\n - property_is_index = " + details[13];
   log = log + "\n - property_is_unique = " + details[14];
   log = log + "\n - property_allow_null = " + details[15];
   log = log + "\n - property_order_level = " + details[16];
   log = log + "\n - property_default_value = " + details[17];
   log = log + "\n - property_format = " + details[18];
   log = log + "\n - property_force_sql_type = " + details[19];
   log = log + "\n - property_force_sql_alias = " + details[20];
   log = log + "\n - property_min_value = " + details[21];
   log = log + "\n - property_max_value = " + details[22];
   log = log + "\n - property_min_length = " + details[23];
   log = log + "\n - property_max_length = " + details[24];
   log = log + "\n - property_reg_exp = " + details[25];
   log = log + "\n - property_accessibility = " + details[26];
   log = log + "\n - property_is_relationship = " + details[27];
   log = log + "\n - property_relation_type = " + details[28];
   log = log + "\n - property_relation_entity_target_id = " + details[29];
   log = log + "\n - property_relation_inverse_property_id = " + details[30];
   log = log + "\n - property_relation_foreign_key = " + details[31];
   log = log + "\n - property_relation_foreign_key_owner = " + details[32];
   log = log + "\n - property_relation_extra_table = " + details[33];
   log = log + "\n - property_relation_type_desc = " + details[34];

   print(log); // print value to the custom script debugger window
   helper.print(log); // print value to the standard output (for example, on Windows, use the 'DebugView' application to see all logs)
   return details;
}

function printEnumerationDetails(enumeration_id)
{
   var details = helper.getEnumerationDetails(enumeration_id);
   if (details.length == 0) { return details; }

   var log = "";
   log = log + "\n - enumeration_id = " + details[0];
   log = log + "\n - enumeration_key = " + details[1];
   log = log + "\n - enumeration_name = " + details[2];
   log = log + "\n - enumeration_namespace = " + details[3];
   log = log + "\n - enumeration_description = " + details[4];
   log = log + "\n - enumeration_version = " + details[5];
   log = log + "\n - enumeration_use_qt_enum_macro = " + details[6];
   log = log + "\n - enumeration_list_of_keys = " + details[7];
   log = log + "\n - enumeration_list_of_values = " + details[8];

   print(log); // print value to the custom script debugger window
   helper.print(log); // print value to the standard output (for example, on Windows, use the 'DebugView' application to see all logs)
   return details;
}

/*
   --- 'file' class methods available by script (QFile wrapper : http://doc.qt.io/qt-5/qfile.html) ---

   bool copy(string fileName, string newName);
   bool exists(string fileName);
   bool link(string fileName, string linkName);
   bool remove(string fileName);
   bool rename(string oldName, string newName);
   string readAll(string fileName);

   void setFileName(string name);
   string fileName();
   bool open(int mode); // enum QIODevice::OpenMode, for example : 26 = (QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text) = (2 + 8 + 16)
   int error(); // enum QFile::FileError
   void close();
   bool atEnd();
   string readLine();
   void write(string text);
*/

/*
   --- 'dir' class methods available by script (QDir wrapper : http://doc.qt.io/qt-5/qdir.html) ---

   void setPath(string path);
   string path();
   string appPath();
   string homePath();
   string rootPath();
   string tempPath();

   string fromNativeSeparators(string pathName);
   string toNativeSeparators(string pathName);

   string cleanPath(string path);
   bool isAbsolutePath(string path);
   bool isRelativePath(string path);
   bool match(string filter, string fileName);

   bool mkdir(string dirName);
   bool mkpath(string dirPath);
   bool rmdir(string dirName);
   bool rmpath(string dirPath);
   bool exists(string name);

   bool cdUp();
   bool cd(string dirName);
   string absoluteFilePath(string fileName);
   string absolutePath();
   string canonicalPath();
   string dirName();
   string filePath(string fileName);
   void refresh();
   string relativeFilePath(string fileName);

   bool isAbsolute();
   bool isReadable();
   bool isRelative();
   bool isRoot();
*/
