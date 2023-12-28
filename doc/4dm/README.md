# 12d Documentation Patching

This project automatically generates the 12dpl library documentation to display
in language services (e.g. showing documentation when hovering over a 12dpl
library function) by mapping the functions defined in a protypes file and
parsing the 12d programming manual with the script `/doc/4dm/gen_doc.py`. This
allows the project to update the documentation efficiently when new versions of
the 12d compiler is released.

The automatic generation allows us to gather the large amount of documentation
very quickly but also comes at a price with many errors such as incorrect spacing
and having pdf header/footer text included in function call descriptions and
including symbol chacaracters in the text. To address this, a documentation
patching system has been implemented to correct the mistakes.

See below for steps on creating a patch.

## How to create a patch

1. Locate the library function you would like to patch in
   `/doc/4dm/generated.json`. For example, if we wanted to
   change the description of the manual item shown below.

   From

   ```json
   {
     "items": [
       {
         "names": ["void Exit(Integer exit_code)"],
         "description": "some wrong description",
         "id": "417"
       }
     ]
   }
   ```

   To

   ```json
   {
     "items": [
       {
         "names": ["void Exit(Integer exit_code)"],
         "description": "Immediately exit the program and write the message macro exited with code exit_code to the information/error message area of the macro console panel.",
         "id": "417"
       }
     ]
   }
   ```

   We need to note down the `id` of the manual item and modify the `description`
   and write a patch.

   A patch follows the structure:

   ```typescript
   type PatchItem = {
     // The function id.
     id: string;
     // New names.
     names?: string[];
     // New description.
     description?: string;
   };
   ```

   So the resulting patch would be:

   ```json
   {
     "id": "417",
     "names": ["void Exit(Integer exit_code)"],
     "description": "Immediately exit the program and write the message macro exited with code exit_code to the information/error message area of the macro console panel."
   }
   ```

2. Add a patch item into `/doc/4dm/patch.json`.

   ```json
   {
     "patches": [
       {
         "id": "417",
         "names": ["void Exit(Integer exit_code)"],
         "description": "Immediately exit the program and write the message macro exited with code exit_code to the information/error message area of the macro console panel."
       }
     ]
   }
   ```

3. Commit changes and open a pull request.
