#include "LineBackgroundPainter.h"

#include <Util.h>

LineBackgroundPainter::LineBackgroundPainter(bool verticalLine)
 : verticalLine(verticalLine)
{
	XOJ_INIT_TYPE(LineBackgroundPainter);
}

LineBackgroundPainter::~LineBackgroundPainter()
{
	XOJ_CHECK_TYPE(LineBackgroundPainter);

	XOJ_RELEASE_TYPE(LineBackgroundPainter);
}

void LineBackgroundPainter::resetConfig()
{
	XOJ_CHECK_TYPE(LineBackgroundPainter);

	this->foregroundColor1 = 0x40A0FF;
	this->foregroundColor2 = 0x5D5D5D;
	this->lineWidth = 0.5;
}

void LineBackgroundPainter::paint()
{
	XOJ_CHECK_TYPE(LineBackgroundPainter);

	paintBackgroundColor();

	paintBackgroundRuled();

	if (verticalLine)
	{
		paintBackgroundVerticalLine();
	}
}

const double roulingSize = 60;

void LineBackgroundPainter::paintBackgroundRuled()
{
	XOJ_CHECK_TYPE(LineBackgroundPainter);

	Util::cairo_set_source_rgbi(cr, this->foregroundColor1);
	cairo_set_line_width(cr, lineWidth * lineWidthFactor);

	for (double y = 30; y < height; y += roulingSize)
	{
		cairo_move_to(cr, 0, y);
		cairo_line_to(cr, width, y);
	}

	cairo_stroke(cr);

	Util::cairo_set_source_rgbi(cr, this->foregroundColor2);
	cairo_set_line_width(cr, lineWidth * lineWidthFactor);

	for (double y = 60; y < height; y += roulingSize)
	{
		cairo_move_to(cr, 0, offset);
		cairo_line_to(cr, width, offset);
		offset += roulingSize;
	}

	cairo_stroke(cr);
}

void LineBackgroundPainter::paintBackgroundVerticalLine()
{
	XOJ_CHECK_TYPE(LineBackgroundPainter);

	Util::cairo_set_source_rgbi(cr, this->foregroundColor2);
	cairo_set_line_width(cr, lineWidth * lineWidthFactor);

	cairo_move_to(cr, 72, 0);
	cairo_line_to(cr, 72, height);
	cairo_stroke(cr);
}
