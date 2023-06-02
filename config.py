def can_build(env, platform):
    return env["target"] == "editor"


def configure(env):
    pass


def get_doc_classes():
    return [
        "PMXMMDState",
        "EditorSceneImporterMMDPMX",
    ]


def get_doc_path():
    return "doc_classes"
