﻿//
// MainPage.xaml.h
// Declaration of the MainPage class.
//

#pragma once

#include "MainPage.g.h"

namespace mandelbrot
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	public ref class MainPage sealed
	{
	public:
		MainPage();
		property Windows::Foundation::Point disP {
			Windows::Foundation::Point get() { return Windows::Foundation::Point(maxP.X - minP.X, maxP.Y - minP.Y); }
		}
	private:
		int limit = 2;
		int max = 256;
		float zoom = 150;
		Windows::Foundation::Point minP;
		Windows::Foundation::Point maxP;
		Windows::Foundation::Point resP;
		bool isRendering = false;
		int fractalChosen = 0;
		Windows::UI::Xaml::DispatcherTimer^ Animator = ref new Windows::UI::Xaml::DispatcherTimer();
		byte* GetPointerToPixelData(Windows::Storage::Streams::IBuffer^ buffer);
		void play_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		/*static int iter(double x, double y, int max, float limit);
		void OnTick(Platform::Object^ sender, Platform::Object^ args);
		void update();*/
		void updateConcurrent();

		//julia specific csts
		double juliaInit = -0.1;
		bool isReversing = false;

		//Mandel specific csts


		void translate(double dx,double dy);
		void Zoom(bool in);

		void Board_PointerWheelChanged(Platform::Object^ sender, Windows::UI::Xaml::Input::PointerRoutedEventArgs^ e);
		void Board_ManipulationDelta(Platform::Object^ sender, Windows::UI::Xaml::Input::ManipulationDeltaRoutedEventArgs^ e);
		void MaxIter_ValueChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs^ e);
		void DivergenceLimit_ValueChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs^ e);
		void Grid_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e);
		void Resolution_ValueChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::Primitives::RangeBaseValueChangedEventArgs^ e);
		void MandelBrot_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void JuliaSet_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Animate_Toggled(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void OnTick(Platform::Object^ sender, Platform::Object^ args);
	};
}
