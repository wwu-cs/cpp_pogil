#!/bin/bash

# Create output directories
mkdir -p pdfs/CS1
mkdir -p pdfs/CS2

# Function to process all subfolders in a given directory
process_folder() {
    local base_dir=$1
    
    # Find all subdirectories (one level deep)
    for dir in "$base_dir"/*/ ; do
        # Skip if not a directory
        [ -d "$dir" ] || continue
        
        # Get the folder name
        folder_name=$(basename "$dir")
        
        # Skip hidden directories and README files
        [[ "$folder_name" == .* ]] && continue
        
        # Look for a .tex file matching the folder name
        tex_file="${dir}${folder_name}.tex"
        
        if [ -f "$tex_file" ]; then
            echo "Processing $tex_file..."
            cd "$dir" || exit
            ../../renderLatexFile.sh "./$folder_name"
            
            # Move the PDF to the output directory
            if [ -f "${folder_name}.pdf" ]; then
                mv "${folder_name}.pdf" "../../pdfs/${base_dir}/${folder_name}.pdf"
                echo "Moved PDF to pdfs/${base_dir}/${folder_name}.pdf"
            fi
            
            cd - > /dev/null || exit
        else
            echo "Skipping $folder_name - no matching .tex file found"
        fi
    done
}

# Process CS1 folder
echo "Processing CS1 activities..."
process_folder "CS1"

# Process CS2 folder
echo "Processing CS2 activities..."
process_folder "CS2"

echo "All done!"
