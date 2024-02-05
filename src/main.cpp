#include <boost/format.hpp>
#include <boost/program_options.hpp>
#include <iostream>
#include <string>

using namespace std;
using boost::format;
using boost::str;
namespace po = boost::program_options;

static const char *appName = "CmakeBoostTemplate";
static const float appVersion = 1.0;
static const format appVersionStr = format("%s - Version: %.2f") % appName % appVersion;
static const format appDescStr = format("%s - Version: %.2f:\n Usage:") % appName % appVersion;
static const format usageStr = format("\
-------------------------------------------------------------------------------\n\
%1% - Version: %2%:\n\
-------------------------------------------------------------------------------\n\
 Options:") % appName % appVersion;
bool silent = false;

static void printVersion() { printf("%s", str(appVersionStr).c_str()); }

static void parseArgs(int argc, char **argv, string &input, string &output, bool &silent) {
    po::options_description desc(str(usageStr));

    // clang-format off
    desc.add_options()
        ("help,h", "Print help message")
        ("input,i", po::value<string>()->required(), "File to be read.")
        ("output,o", po::value<string>(), "File to be written.")
        ("silent,s", "Program output is minimized.  Progress is shown, but generated output is suppressed.")
        ("version,v", "Print version information and exit.");
    // clang-format on

    po::variables_map vm;

    // po::positional_options_description p;
    // p.add("input", 0);
    // p.add("output", 1);
    // po::store(po::command_line_parser(argc,argv).options(desc).positional(p).run(), vm);

    po::store(po::parse_command_line(argc, argv, desc), vm);

    po::notify(vm);

    if (vm.count("version")) {
        printVersion();
        exit(0);
    }

    if (vm.count("help")) {
        cout << desc << endl;
        exit(0);
    }
    if (vm.count("silent")) {
        silent = true;
    }

    if (vm.count("input")) {
        input = vm["input"].as<string>();
    }

    if (vm.count("output")) {
        output = vm["output"].as<string>();
    }
    return;
}

int main(int argc, char **argv) {
    try {
        string input, output = "";
        bool silent = false;
        parseArgs(argc, argv, input, output, silent);
        printf("input: %s   output: %s   silent: %s\n", input.c_str(), output.c_str(), silent ? "true" : "false");
    } catch (exception &e) {
        cerr << "Error: " << e.what() << endl;
        ;
        return 1;
    }

    // Program logic

    return 0;
}
