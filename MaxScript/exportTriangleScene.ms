function isEditableMesh mesh =
(
	return (classof mesh)==Editable_mesh
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

function writeVector2 fptr v =
(
	WriteFloat fptr v[1]
	WriteFloat fptr v[2]	
)

function writeTriangle fptr face =
(
	WriteLong fptr face[1]
	WriteLong fptr face[2]
	WriteLong fptr face[3]	
)

function collectFaces triMesh = 
(
	faceArray = #()
	
	numFaces = getNumFaces triMesh
	for i = 1 to numFaces do
	(
		faceArray[i] = getFace triMesh i
	)
	
	return faceArray
)

function collectVertices triMesh = 
(
	vertexArray = #()
	
	numVerts = getNumVerts triMesh
	for i = 1 to numVerts do
	(
		vertexArray[i] = getVert triMesh i
		vertexArray[i] = vertexArray[i] -- * triMesh.transform
	)
	
	return vertexArray
)

function collectNormals triMesh = 
(
	normalArray = #()
	
	numNormals = getNumVerts triMesh
	for i = 1 to numNormals do
	(
		normalArray[i] = getNormal triMesh i
	)
	
	return normalArray
)

function collectTexCoords triMesh = 
(
	texcoordArray = #()
	
	numTexcoords = getNumVerts triMesh
	for i = 1 to numTexcoords do
	(
		texcoordArray[i] = getTVert triMesh i
	)
	
	return texcoordArray
)

function collectMaterialIDs triMesh = 
(
	materialIDArray = #()
	
	numFaces = getNumFaces triMesh
	for i = 1 to numFaces do
	(
		materialIDArray[i] = getFaceMatID triMesh i
		materialIDArray[i] -= 1
	)
	
	return materialIDArray
)

function collectUniqueMaterialIDs triMesh = 
(
	materialIDArray = #()
	
	numFaces = getNumFaces triMesh
	for i = 1 to numFaces do
	(
		matID = getFaceMatID triMesh i
		matID -= 1
		
		appendIfUnique materialIDArray matID
	)
	
	return materialIDArray
)

function collectSmoothingGroups triMesh = 
(
	smoothingGroupArray = #()
	
	numFaces = getNumFaces triMesh
	for i = 1 to numFaces do
	(
		smoothingGroupArray[i] = getFaceSmoothGroup triMesh i
	)
	
	return smoothingGroupArray
)

function exportTrianglePatch fptr triangleMesh materialID = 
(
	struct vertex (position, normal, texcoord)

	vertexArray = #()
	vertexArray = collectVertices triangleMesh

	normalArray = #()
	normalArray = collectNormals triangleMesh
	
	texCoordArray = #()
	texCoordArray = collectTexCoords triangleMesh
	
	materialIDArray = #()
	materialIDArray = collectMaterialIDs triangleMesh
	
	smoothingGroupArray = #()
	smoothingGroupArray = collectSmoothingGroups triangleMesh
	
	numFaces = getNumFaces triangleMesh

	vertices = #()
	for i = 1 to numFaces do
	(
		matID = getFaceMatID triangleMesh i
		matID -= 1
		if(matID==materialID) do
		(
			face = getFace triangleMesh i
			tvFace = getTVFace triangleMesh i
			
			idx1 = face[1]
			idx2 = face[2]
			idx3 = face[3]
			tvIdx1 = tvFace[1]
			tvIdx2 = tvFace[2]
			tvIdx3 = tvFace[3]

			v1 = vertex position:vertexArray[idx1] normal:normalArray[idx1] texcoord:texCoordArray[idx1]
			v2 = vertex position:vertexArray[idx2] normal:normalArray[idx2] texcoord:texCoordArray[idx2]
			v3 = vertex position:vertexArray[idx3] normal:normalArray[idx3] texcoord:texCoordArray[idx3]
			
			temp = #(v1, v2, v3)
			vertices = vertices + temp
		)
	)
	

	writeLong fptr materialID
	
	numVertices = vertices.count
	writeLong fptr numVertices
	for i = 1 to vertices.count do
	(
		writeVector3 fptr vertices[i].position
		writeVector3 fptr vertices[i].normal
		writeVector2 fptr vertices[i].texcoord
	)
	
	numIndices = vertices.count
	writeLong fptr numIndices
	for i = 1 to numIndices do
	(
		writeShort fptr (i-1)
	)
	
	-- format "% % %\n" materialID numVertices  numIndices  
)

function exportMaterialInfo isCollider fptr triMesh materialID = 
(
	mapNames = #()
	mapFilePaths  = #()
	
	if(triMesh.material.diffuseMapEnable) then
	(
		append mapNames "diffuseMapSampler"
		
		diffuseMapFileName = "default"
		if(triMesh.material.diffuseMap!=undefined) then
			diffuseMapFileName = triMesh.material.diffuseMap.filename
		
		append mapFilePaths diffuseMapFileName
	)
	
	if(triMesh.material.specularMapEnable) then
	(
		append mapNames "specularMapSampler"
		
		specularMapFileName = "default"
		if(triMesh.material.specularMap!=undefined) then
			specularMapFileName = triMesh.material.specularMap.filename
		
		append mapFilePaths specularMapFileName
	)
	
	--writeLong fptr mapNames.count
	for i = 1 to mapNames.count do
	(
		--writeString fptr mapNames[i]
	)
	
	--writeLong fptr mapFilePaths.count
	for i = 1 to mapFilePaths.count do
	(
		--writeString fptr mapFilePaths[i]
	)
)

function exportTriangleMesh fptr triangleMesh = 
(
	uniqueMaterialIDArray = #()
	uniqueMaterialIDArray = collectUniqueMaterialIDs triangleMesh

	writeLong fptr uniqueMaterialIDArray.count
	for i = 1 to uniqueMaterialIDArray.count do
	(
		exportMaterialInfo isCollider fptr triangleMesh uniqueMaterialIDArray[i]
	)
	
	writeLong fptr uniqueMaterialIDArray.count
	for i = 1 to uniqueMaterialIDArray.count do
	(
		exportTrianglePatch fptr triangleMesh uniqueMaterialIDArray[i]
	)
)

function collectTriangleMeshes node =
(
	triangleMeshes = #()

	for i = 1 to node.children.count do
	(
		childNode = node.children[i]
		if(isEditableMesh childNode) then
		(
			triangleMeshes = triangleMeshes + childNode
			collectTriangleMeshes childNode
		)
	)
	
	return triangleMeshes
)

function exportTriangleScene fptr version platform = 
(
	triangleMeshes = collectTriangleMeshes rootNode

	writeLong fptr version
	writeLong fptr platform

	writeLong fptr triangleMeshes.count	
	for i = 1 to triangleMeshes.count do
	(
		exportTriangleMesh fptr triangleMeshes[i]
	)
)

utility ExportTriangleSceneUtility "ExportTriangleSceneUtility"
(
	Button exportTriangleSceneButton "Export Scene"
	
	on exportTriangleSceneButton pressed do
	(
		filename = getSaveFileName caption:"Save File" types:"TriangleScene(*.trianglescene)|*.trianglescene|All|*.*|"

		format "%\n" filename
		if(filename!=undefined) then
		(
			fptr = fopen filename "wb"
			exportTriangleScene fptr 0 1
			fclose fptr
		)
	)
)