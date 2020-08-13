/**
 * @author  {\_Sidewinder22_/}
 * @date    30 lip 2020
 * @file    Utils.cpp
 *
 * @brief   
 */

//---------------------------------------------------------
//                      Includes
//---------------------------------------------------------
#include "ContentUtils.hpp"

//---------------------------------------------------------
//                      Namespace
//---------------------------------------------------------
namespace content
{

ContentUtils::ContentUtils()
	: utils_(std::make_unique<common::CommonUtils>())
{
	// Nothing
}

} // ::content
