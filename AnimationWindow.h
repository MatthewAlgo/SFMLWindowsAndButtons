#pragma once
#ifndef ANIMATION_WINDOW_HEADER_H
#define ANIMATION_WINDOW_HEADER_H
#pragma region INCLUDES
#include "StructuresAndOtherFunctions.h"
#include "MainWindowHeader.h"
#include <iostream>
#include <thread>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#pragma endregion INCLUDES

#pragma region ANIMATION_WINDOW
namespace MatthewsNamespace {
	class AnimationWindow : MatthewsNamespace::MainWindowClass {
	private:
		// Same variables
	public:
		AnimationWindow(const std::string TITLE, int W, int H) : MainWindowClass(TITLE, W, H) {
			// Stuff overriden
		}
		// void DrawInsideMainWindow(sf::RenderWindow* WINDOW, sf::Thread* WINTHREAD, MainWindowClass* C);
		// void RenderTextures(DoubleItemHolder<sf::RenderWindow, MainWindowClass> ITEM_HOLDER);

	};
}
#pragma endregion ANIMATION_WINDOW

#endif