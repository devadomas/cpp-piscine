#ifndef PROJECT_HPP
#define PROJECT_HPP

#define NUMBER_OF_CHARS_IN_VECTOR		10000
#define INSTRUCTION_DECREMENT_BYTE		'-'
#define INSTRUCTION_INCREMENT_BYTE		'+'
#define INSTRUCTION_DECREMENT_POINTER	'<'
#define INSTRUCTION_INCREMENT_POINTER	'>'
#define INSTRUCTION_INPUT				','
#define INSTRUCTION_OUTPUT				'.'
#define INSTRUCTION_JUMP_BACKWARD		']'
#define INSTRUCTION_JUMP_FORWARD		'['

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>

#include "AInstructions.hpp"
#include "InstructionDecrementByte.hpp"
#include "InstructionDecrementPointer.hpp"
#include "InstructionIncrementByte.hpp"
#include "InstructionIncrementPointer.hpp"
#include "InstructionInput.hpp"
#include "InstructionJumpBackward.hpp"
#include "InstructionJumpForward.hpp"
#include "InstructionOutput.hpp"
#include "MindOpen.hpp"

#endif
