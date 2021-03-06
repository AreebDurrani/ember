/*
 Copyright (C) 2011 Peter Szucs

 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software Foundation,
 Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef WEBEMBERMANAGER_H
#define WEBEMBERMANAGER_H

#ifdef _WIN32
#include "platform/platform_windows.h"
#endif

#include "framework/Singleton.h"

#include <string>

namespace Ember
{

/**
 * @brief WebEmbers main platform independent class.
 */
class WebEmberManager: public Singleton<WebEmberManager>
{
public:

	/**
	 * @brief Will start ember and save the hwnd.
	 */
	int start(const std::string& windowhandle, const std::string& prefix = "");

	/**
	 * @brief Will signal quit.
	 *
	 * For safe shutdowns, Ember will not quit immediatelly, but before the next frame.
	 */
	void quit();


	/**
	 * @brief Sends a low-level message to the plugin.
	 *
	 * Message will be processed in WebEmberMessageQueue.
	 * Example: sendMessage("RUN alert('Javascript runs!')")
	 */
	void sendMessage(const std::string& msg);

	/**
	 * @brief Executes javascript code in the browser
	 */
	void runJavascript(const std::string& jscode)
	{
		sendMessage("RUN " + jscode);
	}
private:
	/**
	 * @brief The window handle as a string.
	 */
	std::string mWindowHandle;
};

}

#endif // WEBEMBERMANAGER_H
