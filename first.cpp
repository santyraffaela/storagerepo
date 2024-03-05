  /* Check vertex count per primitive */
                if(indexTuples.size() < 3) {
                    Error() << "Trade::ObjImporter::mesh(): wrong index count for triangle";
                    return Containers::NullOpt;
                } else if(indexTuples.size() != 3) {
                    Error() << "Trade::ObjImporter::mesh(): polygons are not supported";
                    return Containers::NullOpt;
                }

                primitive = MeshPrimitive::Triangles;

  for(const std::string& indexTuple: indexTuples) {
                std::vector<std::string> indexStrings = Utility::String::split(indexTuple, '/');
                if(indexStrings.size() > 3) {
                    Error() << "Trade::ObjImporter::mesh(): invalid index data";
                    return Containers::NullOpt;
                }

                Vector3ui index;

    if(normals.isEmpty() != (normalIndexCount == 0)) {
        Error() << "Trade::ObjImporter::mesh(): incomplete normal data";
        return Containers::NullOpt;
    }
    if(textureCoordinates.isEmpty() != (textureCoordinateIndexCount == 0)) {
        Error() << "Trade::ObjImporter::mesh(): incomplete texture coordinate data";
        return Containers::NullOpt;
