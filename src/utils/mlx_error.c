/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mlx_error.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: W2Wizard <w2.wizzard@gmail.com>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/28 02:51:54 by W2Wizard      #+#    #+#                 */
/*   Updated: 2022/08/08 21:26:29 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42_Int.h"

//= Private =//

// English description of the error codes.
static const char* mlx_errors[MLX_ERRMAX] = {
	[MLX_SUCCESS] = "No Errors",
	[MLX_INVEXT] = "File has invalid extension",
	[MLX_INVFILE] = "Failed to open the file",
	[MLX_INVPNG] = "PNG file is invalid or corrupted",
	[MLX_INVXPM] = "XPM42 file is invalid or corrupted",
	[MLX_INVPOS] = "The specified X or Y positions are out of bounds",
	[MLX_INVDIM] = "The specified Width or Height dimensions are out of bounds",
	[MLX_INVIMG] = "The provided image is invalid, might indicate mismanagement of images",
	[MLX_SHDRFAIL] = "Failed to compile shader",
	[MLX_MEMFAIL] = "Failed to allocate memory",
	[MLX_GLADFAIL] = "Failed to initialize GLAD",
	[MLX_GLFWFAIL] = "Failed to initialize GLFW",
	[MLX_WINFAIL] = "Failed to create window",
	[MLX_STRTOBIG] = "String is to big to be drawn",
};

/**
 * Functions to set the error number, simply for convenience.
 * 
 * @param val The error value.
 * @return Always false 
 */
bool mlx_error(mlx_errno_t val)
{
	mlx_errno = val;
#ifndef NDEBUG
# ifdef _WIN32
	fprintf(stderr, "MLX42: %s", mlx_strerror(mlx_errno));
# else
	warnx("MLX42: %s", mlx_strerror(mlx_errno));
# endif
#endif
	return (false);
}

//= Public =//

const char* mlx_strerror(mlx_errno_t val)
{
	MLX_ASSERT(val >= 0, "Index must be positive");
	MLX_ASSERT(val < MLX_ERRMAX, "Index out of bounds");

	return (mlx_errors[val]);
}
