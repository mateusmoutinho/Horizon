PROJECT_NAME = "PROJECT_NAME"
CONTANIZER   = darwin.argv.get_flag_arg_by_index({ "provider", "contanizer" }, 1, "docker")
VERSION      = "0.0.0"
LICENSE      = "MIT"
URL          = "https://github.com/OUIsolutions/PROJECT_NAME"
DESCRIPITION = "A database with PROJECT_NAMEtal scalability"
FULLNAME     = "OUI Solutions"
EMAIL        = "mateusmoutinho01@gmail.com"
SUMARY       = ""
LAUNGUAGE    = "c"



-- Load all build recipes from builds/ directory
darwin.load_all("builds")