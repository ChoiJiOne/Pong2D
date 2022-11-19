#include "CommandLineUtils.h"
#include "TextUtils.h"

#include <Windows.h>

std::string CommandLineUtils::CommandLine_;
std::vector<std::string> CommandLineUtils::Arguments_;
std::unordered_map<std::string, std::string> CommandLineUtils::Options_;

void CommandLineUtils::Init()
{
	CommandLine_ = GetCommandLineA();
	Arguments_ = TextUtils::Split(CommandLine_, " ");

	for (const auto& Argument : Arguments_)
	{
		if (Argument.find("=") != std::string::npos)
		{
			std::vector<std::string> Tokens = TextUtils::Split(Argument, "=");
			Options_.insert({ Tokens.front(), Tokens.back() });
		}
	}
}

bool CommandLineUtils::HaveOption(const std::string& InOption)
{
	return Options_.find(InOption) != Options_.end();
}

std::string CommandLineUtils::GetValue(const std::string& InOption)
{
	if (!HaveOption(InOption)) return "";

	return Options_.at(InOption);
}
