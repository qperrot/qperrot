#ifndef ENUMS_HPP
#define ENUMS_HPP

/**
 * Enum used to define the receiving state of a request.
 */

enum e_readState {
	StartLine,
	Headers,
	Body,
	Complete,
	Error,
	Unavailable
};

#endif