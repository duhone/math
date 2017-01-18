#pragma once
#include <limits>
#include <algorithm>

namespace CR
{
	namespace Math
	{		
		template<class T>
		class ColorRGB;
		
		template<class T>
		class ColorRGBA
		{
		public:
			T Red{ 0 };
			T Green{ 0 };
			T Blue{ 0 };
			T Alpha{ 0 };

			ColorRGBA(T _red, T _green, T _blue, T _alpha = 0)
			{
				Red = _red;
				Green = _green;
				Blue = _blue;
				Alpha = _alpha;
			}
			ColorRGBA() = default;
	
			template<class S>
			void operator *= (const Color<S> &_arg)
			{
				Red = Clamp(Red*_arg.Red);
				Green = Clamp(Green*_arg.Green);
				Blue = Clamp(Blue*_arg.Blue);
				Alpha = Clamp(Alpha*_arg.Alpha);
			}
			template<class S>
			void operator *= (const ColorRGB<S> &_arg)
			{
				red = Clamp(red*_arg.Red());
				green = Clamp(green*_arg.Green());
				blue = Clamp(blue*_arg.Blue());
			}
		private:
			
			template<class S>
			T Clamp(S _arg)
			{
				T result;
				_arg > std::numeric_limits<T>::max() ? result = std::numeric_limits<T>::max() : result = static_cast<T>(_arg);
				return result;
			}
		};

		typedef Color<unsigned char> Color32;
		typedef Color<float> Color128;		

		template<class T>
		class ColorRGB
		{
		public:
			ColorRGB(T _red, T _green, T _blue)
			{
				red = _red;
				green = _green;
				blue = _blue;
			}
			ColorRGB() : red(0), green(0), blue(0) {}
			
			T Red() const {return red;}
			void Red(T _red) {red = _red;}
			T Green() const {return green;}
			void Green(T _green) {green = _green;}
			T Blue() const {return blue;}
			void Blue(T _blue) {blue = _blue;}		
			void Set(T _red, T _green, T _blue)
			{
				red = _red;
				green = _green;
				blue = _blue;
			}
		private:
			T red;
			T green;
			T blue;
		};
		
		typedef ColorRGB<unsigned char> Color24;
		typedef ColorRGB<float> Color96;	
		
		inline Color32 Color16To32(unsigned short _arg)
		{
			return Color32(((_arg>>11) & 0x01f)<<3,((_arg>>5) & 0x03f)<<2,((_arg) & 0x01f)<<3);
		}
		inline unsigned short Color32To16(const Color32 &_arg)
		{
			return ((_arg.Red()&0x0f8)<<8) | ((_arg.Green()&0x0fc)<<3) | ((_arg.Blue()>>3)&0x01f);
		}
	}
}
