#ifndef _TWRPFUNCTIONS_HPP
#define _TWRPFUNCTIONS_HPP

#include <string>

using namespace std;

typedef enum
{
    rb_current = 0,
    rb_system,
    rb_recovery,
    rb_poweroff,
    rb_bootloader,     // May also be fastboot
    rb_download,
    rb_sboot,
    rb_tboot,
    rb_vboot,
    rb_wboot,
    rb_xboot,
    rb_yboot,
    rb_zboot,
} RebootCommand;

// Partition class
class TWFunc {
	public:
		static int Check_MD5(string File);
		// Trims any trailing folders or filenames from the path, also adds a leading / if not present
		static string Get_Root_Path(string Path);
		// Trims everything after the last / in the string
		static string Get_Path(string Path);
		// Trims the path off of a filename
		static string Get_Filename(string Path);
		// Installs HTC Dumlock
		static void install_htc_dumlock(void);
		// Restores the backup of boot from HTC Dumlock
		static void htc_dumlock_restore_original_boot(void);
		// Reflashes the current recovery to boot
		static void htc_dumlock_reflash_recovery_to_boot(void);
		// Recursively makes the entire path
		static int Recursive_Mkdir(string Path);
		// Gets the size of a folder and all of its subfolders using dirent and stat
		static unsigned long long Get_Folder_Size(const string& Path, bool Display_Error);
		// Returns true if the path exists
		static bool Path_Exists(string Path);
		// Updates text for display in the GUI, e.g. Backing up %partition name%
		static void GUI_Operation_Text(string Read_Value, string Default_Text);
		// Same as above but includes partition name
		static void GUI_Operation_Text(string Read_Value, string Partition_Name, string Default_Text);
		// Returns the size of a file
		static unsigned long Get_File_Size(string Path);
		// Writes the log to last_log
		static void twfinish_recovery(const char *send_intent);
		// Prepares the device for rebooting
		static int tw_reboot(RebootCommand command);
		// checks for the existence of a script, chmods it to 755, then runs it
		static void check_and_run_script(const char* script_file, const char* display_name);
		//execute a command and return the result as a string by reference
		static int Exec_Cmd(string cmd, string &result);
		//recursively remove a directory
		static int removeDir(const string path, bool removeParent);
		//copy file from src to dst with mode permissions
		static int copy_file(string src, string dst, int mode);
		// Returns a dirent dt_type value using stat instead of dirent
		static unsigned int Get_D_Type_From_Stat(string Path);
		// read from file
		static int read_file(string fn, string& results);
		//write from file
		static int write_file(string fn, string& line);
		// Return a diff for 2 times
		static timespec timespec_diff(timespec& start, timespec& end);
		//drop linux cache memory
		static int drop_caches(void);

		// Extended functions
		static bool replace_string(string str, const string search_str, const string replace_str);
		static string to_string(int number);
		static bool Tar_Entry_Exists(string tar_file, string entry, int level);
		static int Get_Archive_Type(string FilePath);
		static unsigned long long Get_Archive_Uncompressed_Size(string FilePath);
		static string Find_File_On_Storage(string Filename);
		static void Take_Screenshot(void);
		static int SubDir_Check(string Dir, string subDir1, string subDir2, string subDir3, string subDir4, string subDir5, int min);

	private:
		static void check_and_fclose(FILE *fp, const char *name);
		static void copy_log_file(const char* source, const char* destination, int append);
};

#endif // _TWRPFUNCTIONS_HPP
