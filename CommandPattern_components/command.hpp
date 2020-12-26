#pragma once

namespace commander {
	class Command {
		// ============== OPERATIONS ==============
	public:
		// ----------- creating ------------
		Command();
		virtual ~Command();

		// ----------- contract ------------
		virtual void execute() = 0;
	};
}
