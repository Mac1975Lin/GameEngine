function isEditableMesh mesh =
(
	return (classof mesh)==Editable_mesh
)

function collectVertices fptr mesh = 
(
	vertexArray = #()
	
	numVerts = getNumVerts mesh
	for i = 1 to numVerts do
	(
		vertexArray[i] = getVert mesh i
	)
	
	return vertexArray
)

function collectFaces fptr mesh baseIdx = 
(
	faceArray = #()
	
	numFaces = getNumFaces mesh
	for i = 1 to numFaces do
	(
		faceArray[i] = getFace mesh i
		faceArray[i][1] += baseIdx-1
		faceArray[i][2] += baseIdx-1
		faceArray[i][3] += baseIdx-1	
	)
	
	return faceArray
)

function collectMaterialIDs fptr mesh = 
(
	materialIDArray = #()
	
	numFaces = getNumFaces mesh
	for i = 1 to numFaces do
	(
		materialIDArray[i] = (getFaceMatID mesh i) - 1
	)
	
	return materialIDArray
)

function writeVector3 fptr v =
(
	WriteFloat fptr v[1]
	WriteFloat fptr v[3]
	WriteFloat fptr -v[2]	
)

function writeTriangle fptr face =
(
	WriteLong fptr face[1]
	WriteLong fptr face[2]
	WriteLong fptr face[3]	
)

function exportBVHTriangleMeshCollider fptr version platform = 
(
	vertexArray = #()
	for i = 1 to rootNode.children.count do
	(
		child = rootNode.children[i]
		if(isEditableMesh child) then
		(
			vertexArray = vertexArray + (collectVertices fptr child)
		)
	)
	
	baseVertexIdx = 0
	faceArray = #()
	for i = 1 to rootNode.children.count do
	(
		child = rootNode.children[i]
		if(isEditableMesh child) then
		(
			faceArray = faceArray + (collectFaces fptr child baseVertexIdx)
		)
		baseVertexIdx = baseVertexIdx + (getNumVerts child)
	)
	
	materialIDArray = #()
	for i = 1 to rootNode.children.count do
	(
		child = rootNode.children[i]
		if(isEditableMesh child) then
		(
			materialIDArray = materialIDArray + (collectMaterialIDs fptr child)
		)
	)
	
	writeLong fptr version
	writeLong fptr platform
	
	writeLong fptr vertexArray.count
	for i = 1 to vertexArray.count do
	(
		writeVector3 fptr vertexArray[i]
	)

	indicesCount = faceArray.count * 3
	writeLong fptr indicesCount
	for i = 1 to faceArray.count do
	(
		writeTriangle fptr faceArray[i]
	)
	
	writeLong fptr materialIDArray.count
	for i = 1 to materialIDArray.count do
	(
		writeLong fptr materialIDArray[i]
	)
	
	format "vertexArray.count=%\n" vertexArray.count
	for i = 1 to vertexArray.count do
	(
		format "vertexArray%=%\n" i vertexArray[i]
	)

	format "faceArray.count =%\n" faceArray.count
	for i = 1 to faceArray.count do
	(
		format "faceArray%=%\n" i faceArray[i]
	)
	
	format "materialIDArray.count =%\n" materialIDArray.count
	for i = 1 to materialIDArray.count do
	(
		format "material%=%\n" i materialIDArray[i]
	)
)

utility ExportBVHTriangleMeshColliderUtility "ExportBVHTriangleMeshColliderUtility"
(
	Button exportButton "Export Button"
	
	on exportButton pressed do
	(
		fptr = fopen "C:/Users/Mac/Desktop/default.bvhtrimesh" "wb"
		exportBVHTriangleMeshCollider fptr 0 1
		fclose fptr
	)
)