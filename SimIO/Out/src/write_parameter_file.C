//
//  Copyright@2013, Illinois Rocstar LLC. All rights reserved.
//
//  See LICENSE file included with this source or
//  (opensource.org/licenses/NCSA) for license information.
//

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Rocout.h"
#include "com_c++.hpp"

using namespace std;
#ifndef DOXYGEN_SHOULD_SKIP_THIS
USE_COM_NAME_SPACE
#endif

void Rocout::write_parameter_file(const char *file_name,
                                  const char *window_name,
                                  const MPI_Comm *comm) {
  // Check to see if the window exists
  COM::COM_base *rbase = COM_get_com();
  int whandle = COM_get_window_handle(window_name);
  COM::Window *param_window = NULL;
  if (whandle > 0) param_window = rbase->get_window_object(whandle);

  COM_assertion_msg(param_window, "Parameter window does not exist");

  // open parameter file for output
  std::ofstream param_file(file_name);
  COM_assertion_msg(file_name,
                    "Specified parameter file can't be opened for writing.");

  // Get all the dataitems of the window
  std::vector<DataItem *> atts;
  param_window->dataitems(atts);

  // Loop through all the dataitems
  // print out those with the correct format.
  for (uint i = 0, ni = atts.size(); i < ni; ++i) {
    if (atts[i]->location() == 'w' && atts[i]->data_type() == COM_CHAR &&
        atts[i]->size_of_components() == 1) {
      std::string option = atts[i]->name();
      std::string value("");
      value.assign((const char *)atts[i]->pointer(), atts[i]->size_of_items());

      param_file << option << " = ";

      if (value.find(" ") != std::string::npos)
        param_file << "\"" << value << "\"\n";
      else
        param_file << value << "\n";
    }
  }
}  // file closed automatically
