#pragma once

#ifndef _RATE_H
#define _RATE_H

class Rate
{
	public:
		// Predefinied rates 
		enum class Presets
		{
			MINIMAL,	// Rate (10)
			LOW,		// Rate (30)
			MEDIUM,		// Rate (60)
			HIGH,		// Rate (90)
			EXTREME,	// Rate (120)
			UNLIMITED	// Rate (Unlimited)
		};

	public:
		Rate();
		Rate(float);
		Rate(Presets);
		~Rate();

		void set(Presets);
		void set(float);

		float get() const;

	protected:

	private:
		float m_Rate;
		float presetToValue(Presets);
};
#endif