#include "script.h"

#ifndef _CAL_H_
#define _CAL_H_

namespace poac{
	namespace script{
		class CCal{
		public:
			bool CalScript(const script::CScript & CalModel, int x);
			bool CalScript(const script::CScript & CalModel, double x);
			double GetResult(){return result;}
		private:
			double result;
		};
	};
};

#endif
