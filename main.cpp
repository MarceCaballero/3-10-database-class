#include <iostream>
#include <string>
// Formularios html
#include "getpost.h"
#include <typeinfo>
#include "persona.h"
#include "myconnection.h"

using namespace std;

int main (int argc, char* const argv[]) {
  // Para formularios
  map<string,string> Post;
  initializePost(Post);

  MyConnection myconnection;
  myconnection.connect();
  sql::ResultSet* res = myconnection.query("Select * from usuarios");

  cout<<"Content-type: text/html"<<endl<<endl;
  cout<<"<html>"<<endl;
  cout<<"<head>"<<endl;
  cout<<"<link href='http://localhost/css/bootstrap.min.css' rel='stylesheet'>"<<endl;
  cout<<"<link href='http://localhost/css/signin.css' rel='stylesheet'>"<<endl;
  cout<<"<link href='http://localhost/css/ejemplo.css' rel='stylesheet'>"<<endl;
  cout<<"</head>"<<endl;

  cout << " <div class='container'>  " << endl;
  cout << "<a class='btn btn-default' role='button'>Link</a> ";

  cout << "      <span class='sr-only'>Toggle navigation</span>  " << endl;
  cout << "      <span class='icon-bar'></span>  " << endl;
  cout << "      <span class='icon-bar'></span>  " << endl;
  cout << "      <span class='icon-bar'></span>  " << endl;
  cout << "    </button>  " << endl;
  cout << "    <a class='navbar-brand' href='#'>Project name</a>  " << endl;
  cout << "  </div>  " << endl;



  cout<<"<div style='text-align:center;'>"<<endl;
  while (res->next()) {
  cout << res->getString("nombre") << "<br>" << endl;
  }
  cout<<"</div>"<<endl;
  cout<<"</body>"<<endl;
  cout<<"</html>"<<endl;


  return 0;
}
