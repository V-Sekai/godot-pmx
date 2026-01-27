# MMD asset importer Plugin for Godot

## What is this?

A Godot 4.6 Plugin for importing Miku Miku Dance Files into Godot. Based on [Godot PMX importer](https://github.com/seanlynch/godot_pmx_importer) module

The objective is to import MMD files to be able to render and work with MMD assets inside godot

### PMX:
- [x] Skeleton
- [x] Mesh
- [ ] Morphs
  - Only vertex morphs are imported
- [x] Materials
  - Only basic textured materials are created
- [ ] IK
  - This is under development.
- [ ] Bone Parent
  - This is under development.
- [ ] Physics
  - For now, use bone modifiers. See below

### VMD (under development):
- Morphs and Motion data has been imported
  - Interpolation is under development

## How do I use it?

Build, then copy the Plugin `addons` folder into your godot `addons` folder,
Activate the plugin in project settings,
then import your MMD files

## Physics

To implement physics simulation you can add bone modifiers (like SpringBones)
This may require tuning

Eventually, a custom bone modifier system could be added to replicate MMD Rigid Body system


## Credits and thanks
- Sean Lynch and iFire
For working in the original PMX importer module

- Lyuma, Tokage and IFire from the V-Sekai discord for their help


