#include <Optimize\rate.h>

Rate::Rate()
{
	m_Rate = presetToValue(Presets::MEDIUM);
}

Rate::Rate(float rate)
{
	m_Rate = rate;
}

Rate::Rate(Presets preset)
{
	m_Rate = presetToValue(preset);
}

Rate::~Rate()
{

}

float Rate::presetToValue(Presets preset)
{
	switch (preset)
	{
	case Rate::Presets::MINIMAL:
		return 10.f;
		break;

	case Rate::Presets::LOW:
		return 30.f;
		break;

	case Rate::Presets::MEDIUM:
		return 60.f;
		break;

	case Rate::Presets::HIGH:
		return 90.f;
		break;

	case Rate::Presets::EXTREME:
		return 120.f;
		break;

	case Rate::Presets::UNLIMITED:
		return -1.f;
		break;

	default:
		return 60.f;
		break;
	
	}
}

void Rate::set(Presets preset)
{
	m_Rate = presetToValue(preset);
}

void Rate::set(float rate)
{
	m_Rate = rate;
}

float Rate::get() const
{
	return m_Rate;
}