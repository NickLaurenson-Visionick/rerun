// TODO(#6330): remove unwrap()
#![allow(clippy::unwrap_used)]

#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Target {
    Cpp,
    Python,
    Rust,

    /// Markdown files shown at <https://rerun.io/docs/reference/types>.
    ///
    /// This target is also used for the markdown strings in the reflection API,
    /// for use with the in-viewer markdown renderer.
    WebDocsMarkdown,
}

/// Implements the codegen pass.
pub trait CodeGenerator {
    /// Generates user-facing code from [`crate::Objects`].
    ///
    /// Returns the expected paths and contents of all generated files.
    /// It is the responsibility of the caller to actually do something with that data (e.g. write
    /// them to disk).
    fn generate(
        &mut self,
        reporter: &crate::Reporter,
        objects: &crate::Objects,
        arrow_registry: &crate::ArrowRegistry,
    ) -> crate::GeneratedFiles;
}

// ---

mod macros {
    #![allow(unused_macros)]
    macro_rules! autogen_warning {
        () => {
            format!(
                "DO NOT EDIT! This file was auto-generated by {}",
                file!().replace("\\", "/")
            )
        };
    }
    pub(crate) use autogen_warning;
}
pub(crate) use macros::autogen_warning; // Hack for declaring macros as `pub(crate)`

// ---

pub(crate) mod common;
use self::common::StringExt;

mod cpp;
mod docs;
mod fbs;
mod python;
mod rust;

pub use self::cpp::CppCodeGenerator;
pub use self::docs::DocsCodeGenerator;
pub use self::fbs::FbsCodeGenerator;
pub use self::python::PythonCodeGenerator;
pub use self::rust::RustCodeGenerator;
