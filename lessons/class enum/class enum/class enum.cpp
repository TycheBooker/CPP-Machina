#include "stdafx.h"

/*enum Animals {Lion, Chicken, Dolphin, Horse};
enum Mammals {Lion, Horse, Dolphin};		*/			// redefinicija - nedozvoljeno

enum class Animals { Lion, Chicken, Dolphin, Horse };
enum class Mammals { Lion, Horse, Dolphin };			// različite klase - vlastiti scope

namespace something										// kad se odvoje namespace-i isti efekt
{
	enum Animals { Lion, Chicken, Dolphin, Horse };
}

namespace somethingElse
{
	enum Mammals { Lion, Horse, Dolphin };
}

int main()
{
    return 0;
}

