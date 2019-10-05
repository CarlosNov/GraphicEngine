#pragma once

#include <stdexcept>

namespace GraphicEngine
{
	/***********************************************************************************************/
	/*                             OPENGL ERROR HANDLING AND CONTROL                               */
	/***********************************************************************************************/

	/**
	*	POST: CLEANS ALL THE PREVIOUS FLAGS IN THE FUNCTION glGetError().
	*/
	static void GLCLearError();

	/**
	 *	PRE: ALL THE FLAGS SHOULD HAVE BEEN CLEANED.
	 *	POST: CHECKS FOR ANY OPENGL ERRORS IN THE SELECTED FUNCTION. IF THERE ARE ANY, PAUSES THE
	 *	      EXECUTION AND PRINTS THE FUNCTION NAME AND THE ERROR LINE.
	 *	ARGUMENTS:
	 *				FUNCTION - NAME OF THE GIVEN FUNCTION.
	 *				LINE - LINE WHERE THE FUNCTION IS BEING EXECUTED.
	 */
	static bool GLLogCall(const char* function, int line);

	/***********************************************************************************************/
	/*										EXCEPTIONS						                       */
	/***********************************************************************************************/

	class ENullptrException : public std::runtime_error
	{
	public:
		ENullptrException(const std::string& w = "Nullprt Exception") : std::runtime_error(w) {}
	};
}
