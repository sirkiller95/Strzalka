// Arrow.h

#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::ComponentModel;

namespace Arrow {							//tutaj jest komentarz

	public ref class BlockArrow : public Control 
	{

	private:
		ArrowDirection direction;
		int thick;

	public:
		BlockArrow()
		{
			Size = System::Drawing::Size(128,1<<7);
			ForeColor = Color::HotPink;
			direction = ArrowDirection::Right;
			thick = 1<<2;
		}

		[ Category("Layout") ]
		property ArrowDirection Direction
		{
			virtual ArrowDirection get() {
				return direction;
			}
			virtual void set(ArrowDirection v) {
				direction = v;
				Invalidate();
			}
		}

		[ Category("Appearance") ]
		property int Thickness
		{
			virtual int get() {
				return thick;
			}
			virtual void set(int v) {
				thick = v;
				Invalidate();
			}
		}

	protected:								//został dodany komentarz
		virtual void OnPaint(PaintEventArgs ^e) override
		{
			int l = ClientRectangle.Left;
			int r = ClientRectangle.Right-1;
			int t = ClientRectangle.Top;
			int b = ClientRectangle.Bottom-1;
			int h = ClientRectangle.Height;
			int w = ClientRectangle.Width;
			// wierzcholki
			Point p1 = Point(l,t);
			Point p2 = Point(l,b);
			Point p3 = Point(r,t+h/2);

			switch (direction)
			{
			case ArrowDirection::Right:	p1 = Point(l,t);
										p2 = Point(l,b);
										p3 = Point(r,t+h/2);
										break;
			case ArrowDirection::Left:	p1 = Point(l,t+h/2);
										p2 = Point(r,b);
										p3 = Point(r,t);
										break;
			case ArrowDirection::Down:	p1 = Point(l+w/2,b);
										p2 = Point(r,t);
										p3 = Point(l,t);
										break;
			case ArrowDirection::Up:	p1 = Point(l+w/2,t);
										p2 = Point(r,b);
										p3 = Point(l,b);
										break;
			}

			array<Point>^ arrowPoints = {p1,p2,p3};
			Pen^ pen = gcnew Pen(Color::Black, thick);
			SolidBrush^ brush = gcnew SolidBrush(ForeColor);
			e->Graphics->FillPolygon(brush,arrowPoints);
			e->Graphics->DrawPolygon(pen,arrowPoints);
		}	//OnPaint

	};	//class BlockArrow


}
