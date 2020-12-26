#pragma once

namespace commander {
	class Command {
		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Command();

		// ----------- contract ------------
		virtual void execute() = 0;
	};
}
