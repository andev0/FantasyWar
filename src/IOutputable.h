#pragma once

#ifndef IOUTPUTABLE_H
#define IOUTPUTABLE_H

#include <iostream>

struct IOutputable
{
public:
	virtual void Show() = 0;
};

#endif // IOUTPUTABLE_H
