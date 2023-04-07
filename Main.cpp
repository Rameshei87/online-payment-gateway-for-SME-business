/*******************************************************************************
 * @file    Main.cpp
 * @brief   This file calle Run fuction to start Enricher module
 ******************************************************************************/
/******************************************************************************
 *  includes:
 *  - system includes
 *  - application includes
 *****************************************************************************/
#include <Enricher.h>
#include <cstdlib>

using namespace MSYS;

/******************************************************************************
 *  definitions:
 *  - macro definitions
 *  - type definitions
 *  - struct definitions
 *****************************************************************************/
/******************************************************************************
 *  constants & variables:
 *  - constants
 *  - external variables
 *  - global variables
 *  - static variables
 *****************************************************************************/

/******************************************************************************
 *  function prototypes:
 *****************************************************************************/

/******************************************************************************
 *  global functions:
 *****************************************************************************/
/******************************************************************************
 *  constructor/destructor:
 *****************************************************************************/

/******************************************************************************
 *  protected functions:
 *****************************************************************************/

/******************************************************************************
 *  private functions:
 *****************************************************************************/

/******************************************************************************
 *  public functions:
 *****************************************************************************/

/******************************************************************************
*	Main function calls Run to start collector   
*****************************************************************************/
int main(int argc, char *argv[])
{
    GlobalDataInfo* l_GDIObjPtr;

    Enricher l_EnricherObj;

    l_GDIObjPtr = new GlobalDataInfo;
	
	char *l_cHomepathPtr = getenv("MSYS_HOME");

    if(NULL == l_cHomepathPtr)
    {
        std::cout << "MSYS_HOME Environment variable is not set. Should be set to an absolute path and one level above the executable file.";
        return 1;
    }
	
	//! Set home path
    std::string l_sHomePath ;

    l_sHomePath.assign(l_cHomepathPtr);

    l_sHomePath.append("Enricher");

	//! Added by Ravi
	l_GDIObjPtr->m_SetQueueWriterRequired(true);
    l_GDIObjPtr->m_SetHomePath(l_sHomePath);
	l_EnricherObj.m_SetComponentType("ENRICHER");
	
	l_EnricherObj.m_SetConfigFileName(l_sHomePath+"/Config/Enricher.cfg");
    l_EnricherObj.Run(l_GDIObjPtr);
	
//	l_GDIObjPtr->m_LoggerObj.m_InitLoggerWriter(2, l_EnricherObj.m_GetComponentName(), l_GDIObjPtr);
    
	if(l_GDIObjPtr)
    {
        delete l_GDIObjPtr;
        l_GDIObjPtr = NULL;
    }

    l_sHomePath.erase();

    return 0;
}

